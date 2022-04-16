
#define OCARN2_IMPLEMENTATION
#include "ocarn2.h"

/**
 * Example to load 3DF data
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char* argv[]) {
    OCARN2::Mesh compass = load_3df_file("testdata/COMPAS.3DF");

    printf("3DF File Contains %d Faces, %d Vertices\n", compass.numFaces, compass.numVertices);
    printf("Texture in 3DF file is %d bytes big\n", compass.textureSize);

    printf("Faces (vert1, vert2, vert3)\n=================\n");
    for(auto& f: compass.faces) {
        printf("(%d, %d, %d)\n", f.v1, f.v2, f.v3);
    }

    // don't forget to free the resources like I did in my initial commit
    free_mesh(compass);

    return 0;
}