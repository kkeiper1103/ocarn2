
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
    OCARN2::Mesh dimorphodon = load_car_file("testdata/DIMOR2.CAR");

    printf("CAR File Contains %d Faces, %d Vertices\n", dimorphodon.numFaces, dimorphodon.numVertices);
    printf("Texture in CAR file is %d bytes big\n", dimorphodon.textureSize);

    printf("Faces (vert1, vert2, vert3)\n=================\n");
    for(auto& f: dimorphodon.faces) {
        printf("(%d, %d, %d)\n", f.v1, f.v2, f.v3);
    }

    free_mesh(dimorphodon);

    return 0;
}