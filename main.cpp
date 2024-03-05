/**
 * Divya Raman
 * CS2240
 * Section A
 */

#include "Album.h"
using namespace std;

int main() {

    // Create vector
    vector<Album> topAlbums;

    // Call decadeCount() if getDataFromFile() is successful
    if(getDataFromFile(topAlbums)) {
        decadeCount(topAlbums);
    }

    return 0;
}