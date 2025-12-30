#version 330

//from Raylib
in vec3 vertexPosition;
in vec2 vertexTexCoord;
in vec4 vertexColor;
in vec3 vertexNormal;

//camera matrix
uniform mat4 mvp;

//to fragment shader
out vec2 fragTexCoord;
out vec4 fragColor;

out vec3 vPosition;
out vec3 vNormal;
out vec2 vUv;
uniform float uTime;

void main() {
    fragTexCoord = vertexTexCoord;
    fragColor = vertexColor;
    vPosition = vertexPosition;
    vNormal = vertexNormal;
    vUv = vertexTexCoord;

    gl_Position = mvp * vec4(vertexPosition, 1.0);
}