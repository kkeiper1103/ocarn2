
#include <vector>

#define OCARN2_IMPLEMENTATION
#include "ocarn2.h"

const int mapSize = 1024;

// bitmap fields
FILE *f;
std::vector<unsigned char> img;
int filesize = 54 + 3*mapSize*mapSize;


/**
 * Example to load MAP data
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char* argv[]) {
    OCARN2::Map map = load_map_file("testdata/AREA1.MAP");

    // not sure the right way to showcase this one. maybe write a bitmap of the heights?
    img = std::vector<unsigned char>(3 * mapSize * mapSize, 0);


    int x, y, r, g, b;

    // this is map's z axis
    for(auto j=0; j < mapSize; j++) {

        // this is map's x axis
        for(auto i=0; i < mapSize; i++) {
            int index = j * mapSize + i;

            unsigned short value = map.lightingMap[0][index];

            x=i; y=(mapSize-1)-j;
            r = value;
            g = value;
            b = value;
            if (r > 255) r=255;
            if (g > 255) g=255;
            if (b > 255) b=255;
            img[(x+y*mapSize)*3+2] = (unsigned char)(r);
            img[(x+y*mapSize)*3+1] = (unsigned char)(g);
            img[(x+y*mapSize)*3+0] = (unsigned char)(b);
        }
    }

    unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
    unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
    unsigned char bmppad[3] = {0,0,0};

    bmpfileheader[ 2] = (unsigned char)(filesize    );
    bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
    bmpfileheader[ 4] = (unsigned char)(filesize>>16);
    bmpfileheader[ 5] = (unsigned char)(filesize>>24);

    bmpinfoheader[ 4] = (unsigned char)(       mapSize    );
    bmpinfoheader[ 5] = (unsigned char)(       mapSize>> 8);
    bmpinfoheader[ 6] = (unsigned char)(       mapSize>>16);
    bmpinfoheader[ 7] = (unsigned char)(       mapSize>>24);
    bmpinfoheader[ 8] = (unsigned char)(       mapSize    );
    bmpinfoheader[ 9] = (unsigned char)(       mapSize>> 8);
    bmpinfoheader[10] = (unsigned char)(       mapSize>>16);
    bmpinfoheader[11] = (unsigned char)(       mapSize>>24);

    f = fopen("dawn-shadowmap.bmp","wb");
    fwrite(bmpfileheader,1,14,f);
    fwrite(bmpinfoheader,1,40,f);
    for(int i=0; i<mapSize; i++)
    {
        fwrite(&img[0] + (mapSize*(mapSize-i-1)*3),3,mapSize,f);
        fwrite(bmppad,1,(4-(mapSize*3)%4)%4,f);
    }

    fclose(f);

    return 0;
}