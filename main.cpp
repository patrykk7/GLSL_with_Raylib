#include "raylib.h"
#include "raymath.h"

int main() {
    InitWindow(800, 600, "Shaders C++");
    SetTargetFPS(60);

    Camera camera = { 0 };
    camera.position = (Vector3){ -4.0f, 0.0f, 0.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Shader myShader = LoadShader("shaders/vertex_shader.vert", "shaders/fragment_shader.frag");
    int timeLoc = GetShaderLocation(myShader, "uTime");
    Mesh planeMesh = GenMeshPlane(2.0f, 2.0f, 1, 1);
    Model planeModel = LoadModelFromMesh(planeMesh);
    //planeModel.transform = MatrixRotateX(DEG2RAD * -90.0f);
    planeModel.transform = MatrixMultiply(MatrixRotateX(DEG2RAD * -90.0f), MatrixRotateZ(DEG2RAD * 180.0f));
    planeModel.materials[0].shader = myShader;

    while (!WindowShouldClose()) {
        float time = GetTime();
        SetShaderValue(myShader, timeLoc, &time, SHADER_UNIFORM_FLOAT);
        UpdateCamera(&camera,CAMERA_THIRD_PERSON);

        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode3D(camera);
                BeginShaderMode(myShader);
                    DrawModel(planeModel, Vector3{0, 0, 0}, 1.0f, WHITE);
                EndShaderMode();
                DrawGrid(10,10);
            EndMode3D();
            DrawFPS(10, 10);
        EndDrawing();
    }

    UnloadModel(planeModel);
    UnloadShader(myShader);
    CloseWindow();
    return 0;
}
