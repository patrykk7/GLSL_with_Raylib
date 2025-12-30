#version 330

//from vertex shader
in vec2 fragTexCoord;
in vec4 fragColor;
in vec3 vPosition;
in vec3 vNormal;
in vec2 vUv;

out vec4 finalColor;

uniform float uTime;

//clamp() - limiter
//bvec3 isEqual = equal(vec3(1),vec3(0)) boolean on vectors
void main() {
    finalColor = vec4(vUv,1.0,1.0);
}
