#include <stdio.h>
#include <math.h>


float func(float a)
{
    float function1 = 2*(pow(a,4)) - (pow(a,3)) + 5*(pow(a,2)) - 12*a + 1;
    //float function1 = pow(a,2)+(54/a);
    return function1;
}


int main()
{
    float decrement, increment, k = 0, delta, x_initial, x_next, pre;

    printf (" \n Enter the initial guess point: ");
    scanf (" %f", &x_initial);
    printf (" \n Enter the increment value: ");
    scanf (" %f", &delta);

    //x_next = 0;
    //delta = 1;

    decrement = x_initial - delta ;
    increment = x_initial + delta ;

    if(func(decrement)>=func(x_initial)&&func(x_initial)<=func(increment))
    {
        printf(" \n The Minimum of the function lies in between %f and %f",decrement, increment);
    }


    else if(func(decrement)<=func(x_initial)&&func(x_initial)>=func(increment)){
        printf("The Given function is not a uni model function, which means it contain two or more minimum points");
    }


    else
    {
        if(func(decrement)>=func(x_initial)&&func(x_initial)>=func(increment))
        {
            delta = delta ;
        }


        else if(func(decrement)<=func(x_initial)&&func(x_initial)<=func(increment))
        {
            delta = -delta ;
        }


        x_next = x_initial + pow(2,k)*(delta) ;
        while(func(x_next)<func(x_initial))
        {
            printf("\nIteration: %.1f\n",k+1);
            printf("function values\nx_initial: %f\nfunction(x_initial): %f\nx_next: %f\nfunction(x_next): %f\n\n",x_initial,func(x_initial),x_next,func(x_next));
            pre = x_initial ;
            x_initial = x_next;

            k++;
            x_next = x_next + pow(2,k)*delta ;
        }
        printf("\nf(x_initial): %f\nf(x_next):%f\nf(x_next) > f(x_initial) is satisfied",func(x_initial),func(x_next));
        printf("\nSo, The Minimum of the function lies in between %f and %f \n The number of iterations are %f",pre,x_next,k);
    }
    return 0;
}
