#ifndef _MODEL_H
#define _MODEL_H

#include "vertex.hpp"

//#include <GLES2/gl2.h>
#include <GLES3/gl3.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

class Model {
private:
    std::vector<Vertex> mesh;
    std::vector<uint16_t> indices;

    GLuint vertex_buffer;
    GLuint index_buffer;
    GLuint texture;

    bool indexed = false;
    bool textured = false;

    glm::mat4 model_matrix = glm::mat4(1.0f);

public:

    Model(std::vector<Vertex>);
    Model(std::vector<Vertex>, std::string);
    Model(std::vector<Vertex>, std::vector<uint16_t>);
    Model(std::vector<Vertex>, std::vector<uint16_t>, std::string);
    GLuint init_vertex_buffer();
    GLuint init_index_buffer();
    GLuint load_texture(const std::string filename);

    glm::mat4 get_model_matrix();
    
    /* tranformations */
    void load_identity();
    void rotate(float, glm::vec3);
    void translate(glm::vec3);
    void scale(glm::vec3);
    void scale(float);

    void draw();
};

#endif
