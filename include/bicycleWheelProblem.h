#define RADIUS 1
#define PI 3.14
#define INTERVALS 1300

#define CIRCUMFERENCE (2 * PI)
#define DIAMETER (2 * RADIUS)
#define MAX_LINEAR_DISTANCE (2 * PI)
#define MAX_VERTICAL_DISTANCE (2 * DIAMETER)

// Instantaneous horizontal distance
#define INSTANTANEOUS_DISTANCE (CIRCUMFERENCE / INTERVALS)

// Data structure declarations

// position of a point, given the distance travelled Linearly and Vertically
typedef struct point
{
    float linearDistance;
    float verticalDistance;

} point;

typedef point graph[INTERVALS];

// function declarations

// total distance travelled by fixed point in 1 revolution
float getTotalDistance(graph pointsList);

// genetrate curve points
void generateGraphPoints(graph pointsList);