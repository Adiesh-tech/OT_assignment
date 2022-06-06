/* program to demonstrate the usage of the bounding phase method in C. */  
#include <stdio.h>  
#include <math.h>
#include <conio.h>
float func(float a)
{
    float f = (a*a*a*a*2)-(a*a*a)+(5*a*a)-(12*a)+1;//the given function
} 
void main()
{
    float start, end, k = 0, delta, x, buff, pre;//declaration of variables
    printf (" \n Enter the initial guess point: ");  // inputing of the initial value
    scanf (" %f", &x);
    printf (" \n Enter the increment value: ");  // inputing of the increment value
    scanf (" %f", &delta);
    start = x - delta ; // the point towards the left of the initial point
    end = x + delta ; // the point towards the right of the initial point
    
    if(func(start)>=func(x)&&func(x)<=func(end))
    {
        printf(" \n The Minimum of the function lies in between %f and %f",start, end);
    }
    else // choosing the sign of the delta value that is increment value
    {
        if(func(start)>=func(x)&&func(x)>=func(end))
        {
            delta = delta ;
        }
        if(func(start)<=func(x)&&func(x)<=func(end))
        {
            delta = -delta ;
        }
    
        buff = x + pow(2,k)*delta ; //itrerative formula to find the next point
        while(func(buff)<func(x))
        {
            pre = x ;
            x = buff ;
            k++;
            buff = x + pow(2,k)*delta ;
        }
        printf(" \n The Minimum of the function lies in between %f and %f",pre,buff);
    }
}