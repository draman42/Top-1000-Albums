/**
 * Divya Raman
 * CS2240
 * Section A
 */

#ifndef PROJECT1_ALBUM_H
#define PROJECT1_ALBUM_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using std::string, std::vector, std::ifstream, std::cout, std::endl, std::ostream;

class Album {
private:
    int position, year;
    double score;
    string artist, albumName;

public:
    // Constructors
    Album() {
        position = year = score = 0;
        artist = "Artist";
        albumName = "Album";
    }
    Album(int position, int year, double score, string artist, string albumName) {
        this->position = position;
        this->year = year;
        this->score = score;
        this->artist = artist;
        this->albumName = albumName;
    }

    // Getters
    int getPosition() const {
        return position;
    }
    int getYear() const {
        return year;
    }
    double getScore() const {
        return score;
    }
    string getArtist() const {
        return artist;
    }
    string getAlbumName() const {
        return albumName;
    }

    // Setters
    void setPosition(int position) {
        this->position = position;
    }
    void setYear(int year) {
        this->year = year;
    }
    void setScore(double score) {
        this->score = score;
    }
    void setArtist(string artist) {
        this->artist = artist;
    }
    void setAlbumName(string albumName) {
        this->albumName = albumName;
    }

    // Overloaded operators
    friend ostream& operator << (ostream& out, const Album& albums) {
        out << albums.position << " - " << albums.albumName;
        out << " by " << albums.artist;
        return out;
    }
    friend bool operator< (const Album& album1, const Album& album2) {
        return(album1.position < album2.position);
    }
    friend bool operator> (const Album& album1, const Album& album2) {
        return(album1.position > album2.position);
    }
    friend bool operator== (const Album& album1, const Album& album2) {
        return(album1.position == album2.position);
    }
    friend bool operator<= (const Album& album1, const Album& album2) {
        return(album1.position <= album2.position);
    }
    friend bool operator>= (const Album& album1, const Album& album2) {
        return(album1.position >= album2.position);
    }


};

bool getDataFromFile(vector<Album>& topAlbums) {
    // Open file for reading
    ifstream fileIn;
    fileIn.open("../top1000albums.csv");

    if(fileIn) {
        // Read first line and store in header
        string header;
        getline(fileIn, header);

        // Declare variables
        int position, year;
        double score;
        string artist, albumName, newline;
        char comma, quotation;

        while(fileIn) {
            // Read position
            fileIn >> position;
            fileIn >> comma; // Read comma

            // Read artist; check first if it is in quotation marks
            // (this indicates there are commas within the artist name)
            if(fileIn.peek() == '"') {
                fileIn >> quotation;
                getline(fileIn, artist, '"');
                fileIn >> comma;
            }
            else {
                getline(fileIn, artist, ',');
            }

            // Read album name; check first if it is in quotation marks
            // (this indicates there are commas within the title)
            if(fileIn.peek() == '"') {
                fileIn >> quotation;
                getline(fileIn, albumName, '"');
                fileIn >> comma;
            }
            else {
                getline(fileIn, albumName, ',');
            }

            // Read year
            fileIn >> year;
            fileIn >> comma; // Read comma

            // Read score
            fileIn >> score;

            // Read the newline character at the end of the line
            getline(fileIn, newline);

            // Store the information as an Album object and add it to the topAlbums vector
            topAlbums.push_back(Album(position, year, score, artist, albumName));
        }


    }
    else {
        cout << "Error opening file" << endl;
        return false;
    }
    // Close file
    fileIn.close();
    return true;
}

// Determine number of top albums in each decade
void decadeCount(vector<Album> topAlbums) {

    // Initialize decade counts
    int pre1950 = 0;
    int the1950s = 0;
    int the1960s = 0;
    int the1970s = 0;
    int the1980s = 0;
    int the1990s = 0;
    int the2000s = 0;
    int the2010s = 0;
    int the2020s = 0;

    // Loop through the topAlbums vector and increment decade counts accordingly
    for(int i = 0; i < topAlbums.size(); i++) {
        int year = topAlbums[i].getYear();
        if(year < 1950) {
            pre1950++;
        }
        else if(year < 1960) {
            the1950s++;
        }
        else if(year < 1970) {
            the1960s++;
        }
        else if(year < 1980) {
            the1970s++;
        }
        else if(year < 1990) {
            the1980s++;
        }
        else if(year < 2000) {
            the1990s++;
        }
        else if(year < 2010) {
            the2000s++;
        }
        else if(year < 2020) {
            the2010s++;
        }
        else {
            the2020s++;
        }
    }

    // Display results
    cout << "Number of Top Albums in Each Decade:" << endl;
    cout << "Pre 1950: " << pre1950 << endl;
    cout << "1950s: " << the1950s << endl;
    cout << "1960s: " << the1960s << endl;
    cout << "1970s: " << the1970s << endl;
    cout << "1980s: " << the1980s << endl;
    cout << "1990s: " << the1990s << endl;
    cout << "2000s: " << the2000s << endl;
    cout << "2010s: " << the2010s << endl;
    cout << "2020s: " << the2020s << endl;
}

#endif //PROJECT1_ALBUM_H
