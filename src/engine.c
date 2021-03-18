#include "shared.h"
#include "structs.h"
#include "graphics/init.h"

const float PI = 3.14159265359;


float deg2rad(float degree)
{
	if (degree < 0)
		return (degree + 360) * (PI / 180);
	else if (degree > 360)
		return (degree - 360) * (PI / 180);
	return degree * (PI / 180);
}

struct Vector angle2vector(float angle)
{
	struct Vector vector;
	vector.x = cos(angle);
	vector.y = sin(angle);
	return vector;
}

float calculateDistance(struct Vector origin, struct Vector destination)
{
	float dx = origin.x - destination.x;
	float dy = origin.y - destination.y;
	return sqrt(pow(dx, 2) + pow(dy, 2));
}

void renderFrame(struct Camera camera, int map[MAP_HEIGHT][MAP_WIDTH], int screenWidth, int screenHeight, float raySpeedModifier)
{
	// init
	#include "graphics/frame.h"
	int block;
	float slice = (float) camera.FOV / screenWidth;
	// render
	for (int rayN = 0; rayN < screenWidth; ++rayN)
	{
		// init rayPosition
		float rayDistance = 0;
		struct Vector rayPosition;
		rayPosition.x = camera.position.x;
		rayPosition.y = camera.position.y;
		// calculate rayVector
		float angle = deg2rad(rayN * slice + camera.angle);
		struct Vector rayVector = angle2vector(angle);
		rayVector.x *= raySpeedModifier;
		rayVector.y *= raySpeedModifier;
		while ((map[(int) rayPosition.y][(int) rayPosition.x] == 0) && (rayDistance <= camera.renderDistance))
		{
			rayPosition.x += rayVector.x;
			rayPosition.y += rayVector.y;
			rayDistance += raySpeedModifier;
		}
		block = map[(int) rayPosition.y][(int) rayPosition.x];
		#include "graphics/draw.h"
	}
	#include "graphics/flip.h"
}

