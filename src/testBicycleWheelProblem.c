#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "testBicycleWheelProblem.h"
#include "bicycleWheelProblem.h"

// function declarations
static void testPointsGenaration();
static void testDistanceCalculation();

void testGraph()
{
    printf("\t\t_______________Starting Unit test_______________\n\n");

    // Start testing
    testPointsGenaration();
    testDistanceCalculation();

    printf("\t\t_______________All tests passed! /-_______________\n\n");
}

static void testPointsGenaration()
{
    // Initializing points list
    graph pointsList = {0};
    point emptyPoint = {(float)0,
                        (float)0};

    generateGraphPoints(pointsList);
    printf("\t\t***Testing point Generation(1/3)***\n\n");

    for (int element = 1; element < INTERVALS - 1; element++)
    {
        assert((pointsList[element].linearDistance != emptyPoint.linearDistance) ||
               (pointsList[element].verticalDistance != emptyPoint.verticalDistance));
    }
    /*
        printf("\t\t***Testing point Generation correctness(2/3)***\n\n");
        int mid = floor((INTERVALS - 1) / 2);
        printf("%d\n", mid);
        if ((INTERVALS - 1) % 2 == 0)
        {
            printf("%f\n", pointsList[mid].verticalDistance);
            assert(pointsList[mid].verticalDistance == (float)1.999999);
        }
        else
        {
            printf("+1 %c\n", pointsList[mid + 1].verticalDistance);
            printf("-1 %f\n", pointsList[mid - 1].verticalDistance);

            assert((pointsList[mid + 1].verticalDistance == (int)1.99) ||
                   (pointsList[mid - 1].verticalDistance == (float)1.99));
        }
    */
    printf("\t\t***Testing point Generation Idempotency(2/3)***\n\n");
    // generate random index value for points list
    srand(3);
    int testIndex = (int)((rand() % (INTERVALS - 4)));

    assert((pointsList[testIndex + 1].linearDistance != pointsList[testIndex].linearDistance) &&
           (pointsList[testIndex + 1].verticalDistance != pointsList[testIndex].verticalDistance) &&
           //
           (pointsList[testIndex + 2].linearDistance != pointsList[testIndex].linearDistance) &&
           (pointsList[testIndex + 2].verticalDistance != pointsList[testIndex].verticalDistance) &&
           //
           (pointsList[testIndex + 3].linearDistance != pointsList[testIndex].linearDistance) &&
           (pointsList[testIndex + 3].verticalDistance != pointsList[testIndex].verticalDistance));
}

static void testDistanceCalculation()
{
    point testPoint = {2.0f, 0.0f};
    graph testArray = {0};
    for (int i = 1; i < 3; i++)
    {
        testArray[i] = testPoint;
    }

    printf("\t\t***Testing distance calculation(3/3)***\n\n");
    assert(4.0f == getTotalDistance(testArray));
}