#include "shared.h"
#include "structs.h"

float deg2rad(float degree);
struct Vector normalizeVector(struct Vector vector);
float calculateDistance(struct Vector origin, struct Vector destination);
void renderFrame(struct Camera camera, int map[MAP_HEIGHT][MAP_WIDTH], int screenWidth, int screenHeight, float raySpeedModifier);

