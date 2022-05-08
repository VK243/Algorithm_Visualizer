
                    /*Preprocessor header links*/
#include<stdio.h>
#include<stdlib.h>
#include<GL\glut.h>
#include<string.h>

                    /*Defining constants*/

//number of array values
#define MAX 50
//number of algorithms
#define SORT_NO 4
//speed of execution of algorithms
#define SPEED 600

                    /*Initializing variables*/
//array creation
int a[MAX];
//flag to swap
int swapflag=0;
//to move/iterate through array
int i=0,j=0;
//for insertion sort
int flag=0;
//for ripple sort, for changing direction
int dflag=0;
//for ripple sort, to keep count of sorted ones
int counts=1;
//for switching form welcome screen to next screen
int k=0;
//value if 1 sorted
int sorting=0;
//sorting names
char *sort_string[]={"Bubble Sort", "Selection Sort", "Insertion Sort", "Ripple Sort"};
//for cycling through sort string
int sort_count=0;


                     /*Functions*/

void bitmap_output(int x,int y, char *string_a, void *font)
{
    int len, z;

    glRasterPos2f(x,y);
    len = (int) strlen(string_a);
    for (i=0;i<len;i++)
    {
        glutBitmapCharacter(font, string_a[i]);
    }
}

void display_text()
{
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f,0.0f,0.5f);
    bitmap_output(150,665,"DYNAMIC ALGORITHM VISUALIZER",GLUT_BITMAP_TIMES_ROMAN_24);
    glBegin(GL_LINE_LOOP);
    glVertex2f(145,660);
    glVertex2f(520,660);
    glEnd();

    bitmap_output(10,625,"Sorting from random to ascending order",GLUT_BITMAP_9_BY_15);

    if(sorting == 0)
    {
        bitmap_output(10,575,"MENU :",GLUT_BITMAP_9_BY_15);
        bitmap_output(10,555,"SORT Press s",GLUT_BITMAP_9_BY_15);
        bitmap_output(10,535,"Select Algorithm Press c",GLUT_BITMAP_9_BY_15);
        bitmap_output(10,515,"SHUFFLE Press r",GLUT_BITMAP_9_BY_15);
        bitmap_output(10,495,"QUIT Press ESC",GLUT_BITMAP_9_BY_15);
        bitmap_output(10,475,"Select Sort:",GLUT_BITMAP_9_BY_15);
        bitmap_output(150,475,*(sort_string+sort_count),GLUT_BITMAP_9_BY_15);
    }
    else if(sorting == 1)
    {
        glColor3f(0.5,0.5,0.5);
        bitmap_output(10,555,"Sorting in Process...",GLUT_BITMAP_9_BY_15);
        bitmap_output(10,535,"PAUSE Press p",GLUT_BITMAP_9_BY_15);
        glColor3f(0.0,0.0,0.0);
    }

}

void int_str(int ra, char r[])
{
    itoa(ra,r,10);
}

void front_frame()
{
    glColor3f(22.4,100,7.8);

    bitmap_output(200,475, "DYNAMIC ALGORITHM VISUALIZER",GLUT_BITMAP_TIMES_ROMAN_24);
    glBegin(GL_LINE_LOOP);
    glVertex2f(195,470);
    glVertex2f(500,470);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(520,120.0);
    glVertex2f(520,170);
    glVertex2f(796,170);
    glVertex2f(796,120.0);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    bitmap_output(530,135, "Press ENTER to continue..",GLUT_BITMAP_HELVETICA_18);

}

//returning zero if not sorted
int notsorted()
{

    int p;
    for(p=0;p<MAX;p++)
    {
        if(a[p]>a[p+1])
            return 1;
    }

    return 0;
}

void Initialize()
{
    int temp;

    //reset array
    for(temp=0;temp<MAX;temp++)
    {
        a[temp]=rand()%100+1;
        printf("%d",a[temp]);
    }

    //reset values
    i=j=dflag=flag=0;
    counts=1;

    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,699,0,799);

}


void display()
{
    int x,temp;

    glClearColor(0.2f,0.2f,0.2f,0);
    glClear(GL_COLOR_BUFFER_BIT);


    if(k==0)
    {
        front_frame();
    }
    else
    {
        display_text();

        char text[10];
        for(x=0;x<MAX;x++)
        {
            glColor3f(1,0,0);
            glBegin(GL_LINE_LOOP);
            glVertex2f(10+(700/(MAX+1))*x,50);
            glVertex2f(10+(700/(MAX+1))*(x+1),50);
            glVertex2f(10+(700/(MAX+1))*(x+1),50+a[x]*4);
            glVertex2f(10+(700/(MAX+1))*x,50+a[x]*4);
            glEnd();

            int_str(a[x],text);

            glColor3f(0,0,0);
            bitmap_output(12+(700/(MAX+1))*x, 35, text, GLUT_BITMAP_TIMES_ROMAN_10);
        }

        if(swapflag || sorting == 0)
        {
            glColor3f(0,0,1);
            glBegin(GL_POLYGON);
            glVertex2f(10+(700/(MAX+1))*j,50);
            glVertex2f(10+(700/(MAX+1))*(j+1),50);
            glVertex2f(10+(700/(MAX+1))*(j+1),50+a[j]*4);
            glVertex2f(10+(700/(MAX+1))*j,50+a[j]*4);
            glEnd();
            swapflag=0;
        }
    }
    glFlush();
}



void makedelay(int)
{
    if(sorting)
    {
        switch(sort_count)
        {
            case 0:
                {
                  break;
                }
            case 1:
                {
                  break;
                }
            case 2:
                {
                  break;
                }
            case 3:
                {
                  break;
                }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(SPEED/MAX,makedelay,1);
}


void keyboard(unsigned char key, int x, int y)
{
    if(key==13)
    {
        k=1;
    }
    if(k==1 && sorting!=1)
    {
        switch(key)
        {
        case 27:
            {
                exit(0);
            }
        case 's':
            {
                sorting=1;
                break;
            }
        case 'r':
            {
                Initialize();
                break;
            }
        case 'c':
            {
                sort_count=(sort_count+1)%SORT_NO;
                break;
            }
        }
    }
    if(k==1 && sorting==1)
    {
        if(key=='p')
            sorting =0;
    }
}







//Main function

int main (int argc, char **argv)
{

    glutInit(&argc,argv);
    //Initializing display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //Initializing window size
    glutInitWindowSize(1000,600);
    //Initializing window position
    glutInitWindowPosition(0,0);
    //creating a window
    glutCreateWindow("Dynamic Algorithm Visualizer");
    //Initializing
    Initialize();
    //calling display function
    glutDisplayFunc(display);
    //calling keyboard function
    glutKeyboardFunc(keyboard);
    //calling timer function
    glutTimerFunc(1000,makedelay,1);
    //Initializing main function loop
    glutMainLoop();
}
