/* program to demonstrate the usage of the bounding phase method in C. */
#include <stdio.h>
#include <math.h>
float func(float a)
{
    float function1 = 2*(pow(a,4)) - (pow(a,3)) + 5*(pow(a,2)) - 12*a + 1;// the given function
    //float function1 = pow(a,2)+(54/a);
    return function1;
}
int main()
{
    float start, end, k = 0, delta, x, buff, pre;//declaration of variables
    printf (" \n Enter the initial guess point: ");  // inputing of the initial value
    scanf (" %f", &x);
    printf (" \n Enter the increment value: ");  // inputing of the increment value
    scanf (" %f", &delta);
    //x = 0;
    //delta = 1;
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

        buff = x + pow(2,k)*delta ; //iterative formula to find the next point
        while(func(buff)<func(x))
        {
            printf("\n");
            printf("Iteration: %.1f\n",k+1);
            pre = x ;
            x = buff ;
            printf("function values\n");
            printf("function(x): %f\n",func(x));
            printf("function(buff): %f\n",func(buff));
            printf("\n");
            k++;
            buff = x + pow(2,k)*delta ;
        }
        printf(" \n The Minimum of the function lies in between %f and %f",pre,buff);
        printf(" \n The number of iterations are %f",k);
    }
    return 0;
}
