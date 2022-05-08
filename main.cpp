
                    /*Preprocessor header links*/
#include<stdio.h>
#include<stdlib.h>
#include<GL\glut.h>
#include<string.h>

                    /*Defining constants*/

//number of array values
#define MAX 50
//number of algorithms
#define ALGO_NO 4
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
//for ripple dort, to keep count of sorted ones
int count=1;
//for switching form welcome screen to next screen
int k=0;
//value if 1 sorted
int sorting=0;
//sorting names
char *sort_string[]={"Bubble Sort", "Selection Sort", "Insertion Sort", "Ripple Sort"};
//for cycling through sort_string
int sort_count=0;


void Initialize()
{


}


void display()
{


}



void makedelay(int)
{


}


void keyboard(usigned char key, int x, int y)
{


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
