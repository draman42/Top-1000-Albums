/**
 * Author: Divya Raman
 * This program demonstrates the functionality of class "Album.h"
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
