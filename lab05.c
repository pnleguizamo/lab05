/*----------------------------------------------------------------------------
-		         SE 185: Lab 05 - Conditionals (What's up?)	    	         -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab05.c -o lab05
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -a -g -b | ./lab05

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/

int closeTo(double tolerance, double point, double value);
int checkPos(double gx, double gy, double gz, double xValue, double yValue, double zValue);
double magnitude(double x, double y, double z);
int checkOrientation(int currOrientation, int masterOrientation);

double const tolerance = .2;

int main(int argc, char *argv[])
{
    int triangle, circle, x_button, square;
    double ax, ay, az, gx, gy, gz;

    // Expected G values for top
    double xValueTop = 0.02;
    double yValueTop = 0.98;
    double zValueTop = 0.22;

    // Expected G values for Bottom
    double xValueBottom = 0.02;
    double yValueBottom = -0.98;
    double zValueBottom = -0.08;

    // Expected G values for left
    double xValueLeft = 0.98;
    double yValueLeft = 0.11;
    double zValueLeft = 0.05;

    // Expected G values for Right
    double xValueRight = -0.98;
    double yValueRight = 0.11;
    double zValueRight = 0.06;

    // Expected G values for Front
    double xValueFront = 0.02;
    double yValueFront = 0.42;
    double zValueFront = -0.9;
    
    // Expected G values for Back
    double xValueBack = .005;
    double yValueBack = -0.115;
    double zValueBack = 0.99;

    int currOrientation;
    int masterOrientation = 0; 
    // int switchVar = 0;

    

    while (1)
    // for (int i = 0; i<630; i++)
    {
        // a for acceleration, g for gyro, button
        scanf("%lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d",
              &ax, &ay, &az, &gx, &gy, &gz, &triangle, &circle, &x_button, &square);
        // printf("%lf", triangle);

        /* printf for observing values scanned in from ds4rd.exe,
         * be sure to comment or remove in final program */
        printf("Echoing output: %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n",
               ax, ay, az, gx, gy, gz, triangle, circle, x_button, square);

        // if(switchVar == 1){
            // Check top
            if(checkPos(gx, gy, gz, xValueTop, yValueTop, zValueTop)){
                currOrientation = 0;
                
            }
            // Check bottom
            if(checkPos(gx, gy, gz, xValueBottom, yValueBottom, zValueBottom)){
                currOrientation = 1;                
                
            }
            // Check left
            if(checkPos(gx, gy, gz, xValueLeft, yValueLeft, zValueLeft)){
                currOrientation = 2;
                
            }
            // check right 
            if(checkPos(gx, gy, gz, xValueRight, yValueRight, zValueRight)){
                currOrientation = 3;
                
            }
            // check front
            if(checkPos(gx, gy, gz, xValueFront, yValueFront, zValueFront)){
                currOrientation = 4;
                
            }
            // check back
            if(checkPos(gx, gy, gz, xValueBack, yValueBack, zValueBack)){
                currOrientation = 5;
            }

        //}

        if(triangle == 1.0){
            break;
        }

        masterOrientation = checkOrientation(currOrientation, masterOrientation);

        /* It would be wise (mainly save time) if you copy your code to calculate
         * the magnitude from lab03-1.c. You will also need to copy your
         * prototypes and functions to the appropriate sections in this program. */

        // printf("The acceleration's current magnitude is: %lf\n", magnitude(ax, ay, az));
    }

    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */

// Check current position against knowns

double magnitude(double x, double y, double z)
{
    // Step 8, uncomment and modify the next line
    double magnitudeSquare = pow(x, 2) + pow(y, 2) + pow(z, 2);
    return sqrt(magnitudeSquare);
}

int checkOrientation(int currOrientation, int masterOrientation){
    if(currOrientation!=masterOrientation){
            //printf("%d",currOrientation);
            if(currOrientation == 0){
                printf("Top\n");
            }    
            if(currOrientation == 1){
                printf("Bottom\n");
            }  
            if(currOrientation == 2){
                printf("Left\n");
            }  
            if(currOrientation == 3){
                printf("Right\n");
            }  
            if(currOrientation == 4){
                printf("Front\n");
            }  
            if(currOrientation == 5){
                printf("Back\n");
            }  
            masterOrientation = currOrientation;
        }
        
        return masterOrientation;
}

int closeTo(double tolerance, double point, double value){
    double toleranceValLow = value-tolerance;
    double toleranceValHigh = value + tolerance;
    
    if (toleranceValLow<point && point<toleranceValHigh){
        // printf("Low: %lf\n High: %lf\n", toleranceValLow, toleranceValHigh);
        // printf("Point val: %lf\n", point);
        // printf("close to \n");
        return 1;
    }
    else{
        // printf("Not close to \n");
        return 0;
    }

}

int checkPos(double gx, double gy, double gz, double xValue, double yValue, double zValue){
    int count = 0;
    
    if(closeTo(tolerance, gx, xValue) && closeTo(tolerance, gy, yValue) && closeTo(tolerance, gz, zValue)){
        // printf("%lf\n", gx);
        return 1;
    }
    // if(closeTo(tolerance, gy, yValue)){
    //     // printf("%lf\n", gx);
    //     count++;
    // }
    // if(closeTo(tolerance, gz, zValue)){
    //     // printf("%lf\n", gz);
    //     count++;
    // }
    // if(count==3){
    //     return 1;

    // }

}

int isBottom(double gx, double gy, double gz){
    
    double xValue = 0.02;
    double yValue = -0.98;
    double zValue = -0.08;
    int count = 0;
    
    if(closeTo(tolerance, gx, xValue)){
        // printf("%lf\n", gx);
        count++;
    }
    if(closeTo(tolerance, gy, yValue)){
        // printf("%lf\n", gx);
        count++;
    }
    if(closeTo(tolerance, gz, zValue)){
        // printf("%lf\n", gz);
        count++;
    }
    if(count==3){
        return 1;

    }

}
