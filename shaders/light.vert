#version 300 es

precision highp float;

layout (location = 0) in vec3 position;

uniform mat4 mvp;

void main(void) {
    gl_Position = mvp * vec4(position, 1.0);
}
