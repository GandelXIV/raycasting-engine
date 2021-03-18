struct Vector
{
        float x;
        float y;
};

struct Camera
{
        struct Vector position; // center
        float angle;
        int FOV;
        float renderDistance;
}; 
