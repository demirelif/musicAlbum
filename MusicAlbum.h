//
//  MusicAlbum.h
//  HW_1
//
//  Created by Elif Demir on 17.11.2018.
//  Copyright © 2018 Elif Demir. All rights reserved.
//
#ifndef __MUSIC_ALBUM_H
#define __MUSIC_ALBUM_H
#include <string>
using namespace std;
#include "Song.h"
class MusicAlbum {
public:
    MusicAlbum(const string maArtist = "",
               const string maTitle = "",
               const int maYear = 0);
    ~MusicAlbum();
    MusicAlbum(const MusicAlbum &maToCopy);
    void operator=(const MusicAlbum &right);
    string getMusicAlbumArtist();
    string getMusicAlbumTitle();
    int getMusicAlbumYear();
    void calculateMusicAlbumLength(int &minutes, int &seconds);
    int getSongs(Song *&allSongs);
    bool createSong( string sName, int sMins, int sSecs);
    void resetSongList();
    int getNumberOfSongs() const;

private:
    string artist;
    string title;
    int year;
    Song *songs;
    int noSongs;
};
#endif
