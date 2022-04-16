
#define OCARN2_IMPLEMENTATION
#include "ocarn2.h"

/**
 * Example to load RSC data
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char* argv[]) {
    OCARN2::Rsc resources = load_rsc_file("testdata/AREA1.RSC");

    printf("RSC file contains %d textures, %d simple models\n", resources.numTextures, resources.numModels);
    printf("RSC file contains %d sounds, %d ambient noises\n", resources.numSoundEffects, resources.numAmbientSounds);
    printf("RSC file contains %d fogs, %d water definitions\n", resources.numFogs, resources.numWaters);

    printf("\nSounds\n"); int i=0;
    for(auto& sfx: resources.soundEffects) {
        printf("Sound %d: %d bytes long\n", ++i, sfx.length);
    }

    printf("\nFog Colors: (r, g, b) - KillsPlayer?\n");
    for(auto& f: resources.fogs) {
        printf("%d, %d, %d - %d\n", f.color.r, f.color.g, f.color.b, f.isMortal);
    }

    return 0;
}