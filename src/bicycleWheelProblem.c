#include <stdio.h>
#include <math.h>
#include "bicycleWheelProblem.h"
#include "testBicycleWheelProblem.h"

int main(int argc, char *argv[])
{
    // unit test
    testGraph();

    // initialize the list of point with 0
    graph pointsList = {0};
    // genetrate curve points given tha radius of circle as 1
    generateGraphPoints(pointsList);

    // total distance travelled by fixed point in 1 revolution
    float totalDistance = getTotalDistance(pointsList);

    // print the distance
    printf("Total distance travelled by a point after\n");
    printf("1 complete rotation of wheel is %.2f",
           totalDistance);
}

void generateGraphPoints(graph pointsList)
{
    float angle = 0;
    int interval = 0;
    while (interval < INTERVALS)
    {
        pointsList[interval].linearDistance = RADIUS * (angle - sin(angle)); // Hyp*(t - sin(t)) = Prependicular
        pointsList[interval].verticalDistance = RADIUS * (1 - cos(angle));   // Hyp * (1 -  cos(t)) = Base

        // adding the horizontal distance to linear distance coordinate as correction factor
        // New equation;   Hyp * cos() = Base + instantaneous Horizontal Distance
        // pointsList[interval].linearDistance += instantaneousDistance;
        // incrementing angle value
        angle += INSTANTANEOUS_DISTANCE;
        interval++;
    }
}

/*
void generateGraphPoints(graph pointsList)
{
    float angle = 0;
    int interval = 0;
    while (interval < INTERVALS)
    {
        pointsList[interval].linearDistance = RADIUS * cos(angle);   // Hyp * cos() = Base
        pointsList[interval].verticalDistance = RADIUS * sin(angle); // Hyp * sin() = Prependicular

        // adding the horizontal distance to linear distance coordinate as correction factor
        // New equation;   Hyp * cos() = Base + instantaneous Horizontal Distance
        // pointsList[interval].linearDistance += INSTANTANEOUS_DISTANCE;
        // incrementing angle value
        angle += INSTANTANEOUS_DISTANCE;
        interval++;
    }
}
*/

float getTotalDistance(graph pointsList)
{
    float xCoords;
    float yCoords;
    float sumSquares;

    float tDistance = 0.0f;
    for (int point = 0; point < (INTERVALS - 1); point++)
    {
        xCoords = pointsList[point + 1].linearDistance - pointsList[point].linearDistance;
        yCoords = pointsList[point + 1].verticalDistance - pointsList[point].verticalDistance;

        sumSquares = powf(xCoords, 2) + powf(yCoords, 2);

        tDistance += sqrtf(sumSquares);
    }
    return tDistance;
}