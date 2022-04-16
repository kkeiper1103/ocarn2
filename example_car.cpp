
#define OCARN2_IMPLEMENTATION
#include "ocarn2.h"

/**
 * Example to load CAR data
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char* argv[]) {
    OCARN2::Mesh compass = load_car_file("testdata/DIMOR2.CAR");

    printf("CAR File Contains %d Faces, %d Vertices\n", compass.numFaces, compass.numVertices);
    printf("Texture in CAR file is %d bytes big\n", compass.textureSize);

    printf("Faces (vert1, vert2, vert3)\n=================\n");
    for(auto& f: compass.faces) {
        printf("(%d, %d, %d)\n", f.v1, f.v2, f.v3);
    }

    return 0;
}