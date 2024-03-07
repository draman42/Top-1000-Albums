# Top-1000-Albums
In this project, I chose a data set containing 1000 albums, wrote a class in C++ to represent its information, read each record of data into a vector, and performed a calculation on the data.

**The Data:**
  - Collected from https://tsort.info/music/albums.htm
  - You may reference "top1000albums.csv" to view the data
  - The data set contains 1000 "top albums" which were ranked according to Tsort's comprehensive scoring system
  - Attributes:
      - Position (each album is ranked from 1-1000)
      - Score (score determined by Tsort)
      - Artist
      - Album Name
      - Year Released

**Album.h:**
  - This C++ class represents an "Album" object, containing each attribute of the data set as fields
  - Fields:
      - Integers: position, year
      - Double: score
      - Strings: artist, albumName
  - Method getDataFromFile():
      - This method takes in an empty vector (topAlbums), opens a text file (top1000albums.csv), and reads the data into the vector
      - Each line of data is stored as a certain Album field (position, year, score, artist, or albumName)
      - After one Album is read, it is added as an Album object into the topAlbums vector, and the process repeats until there is no more data to be read
      - When complete, the topAlbums vector contains 1000 Album objects, and the method returns "true" to indicate success
  - Method decadeCount():
      - This method takes in the vector containing 1000 albums (topAlbums), loops through the vector, and counts the number of albums in each decade
      - When complete, the method displays the result of its calculations

**Main.cpp:**
  - In main, an empty vector is created (topAlbums)
  - The vector is passed into the getDataFromFile() method
  - If successful, the method decadeCount() is called and its results are displayed
  
