//
//  MusicAlbum.cpp
//  HW_1_B
//
//  Created by Elif Demir on 18.11.2018.
//  Copyright © 2018 Elif Demir. All rights reserved.
//

#include "MusicAlbum.h"
#include <string>
#include "Song.h"
#include <iostream>
using namespace std;

MusicAlbum :: MusicAlbum( const string maArtist, const string maTitle, const int maYear){
    songs = NULL;
    noSongs = 0;
    artist = maArtist;
    title = maTitle;
    year = maYear;
}

MusicAlbum::~MusicAlbum(){
    if ( songs )
        delete[] songs;
}

MusicAlbum :: MusicAlbum(const MusicAlbum &maToCopy){
    artist = maToCopy.artist;
    title = maToCopy.title;
    year = maToCopy.year;
    //noSongs = maToCopy.getNumberOfSongs();
    
    if ( noSongs > 0){
        songs = new Song[ noSongs ];
        for ( int i = 0; i < noSongs; i++){
            songs[i] = maToCopy.songs[i];
        }
    }
    else
        songs = NULL;
}

void MusicAlbum :: operator =(const MusicAlbum &right){
    if ( &right != this ) {
        artist = right.artist;
        title = right.title;
        year = right.year;
        if( noSongs != right.noSongs ){
            if ( noSongs > 0)
                delete[] songs;
            noSongs = right.noSongs;
            if ( noSongs > 0)
                songs = new Song[noSongs];
            else
                songs = NULL;
        }
        for ( int i = 0; i < noSongs; i++)
            songs[i] = right.songs[i];
    }
}

string MusicAlbum :: getMusicAlbumArtist() {
    return artist;
}
string MusicAlbum :: getMusicAlbumTitle() {
    return title;
}
int MusicAlbum :: getMusicAlbumYear() {
    return year;
}

void MusicAlbum :: calculateMusicAlbumLength(int &minutes, int &seconds){
    int albumLengthM = 0;
    int albumLengthS = 0;
    
    for ( int i = 0; i < noSongs; i++)
    {
        albumLengthM = albumLengthM + songs[i].getMins();
        albumLengthS = albumLengthS + songs[i].getSecs();
    }
    if ( albumLengthS > 59 ){
        albumLengthM = albumLengthM + (albumLengthS / 60);
        albumLengthS = albumLengthS % 60;
    }
    minutes = albumLengthM;
    seconds = albumLengthS;
}

bool MusicAlbum :: createSong( string sName, int sMins, int sSecs){
    Song newSong(sName, sMins, sSecs);
    if ( songs == NULL ){
        songs = new Song[1];
        songs[0] = newSong;
        noSongs++;
        return true;
    }
    else {
        for ( int i = 0; i < noSongs; i++ ){
            if ( songs[i].getName() == sName ){
                return false;
            }
        }
        Song * temp = songs;
        songs = new Song[ noSongs + 1];
        for ( int j = 0; j < noSongs; j++ ){
            songs[j] = temp[j];
        }
        songs[noSongs] = newSong;
        noSongs++;
        delete [] temp;
        return true;
    }
}

int MusicAlbum:: getSongs(Song *&allSongs){
    if ( allSongs != NULL ){
        delete[] allSongs;
    }
    allSongs = new Song[noSongs];
    for( int i = 0; i < noSongs; i++)
    {
        allSongs[i] = songs[i];
    }
    return noSongs;
}

void MusicAlbum:: resetSongList(){
    delete[] songs;
}

//int MusicAlbum:: getNumberOfSongs() const{
//    return noSongs;
//}
