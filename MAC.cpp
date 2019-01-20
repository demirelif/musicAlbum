//
//  MAC.cpp
//  HW_1_B
//
//  Created by Elif Demir on 18.11.2018.
//  Copyright © 2018 Elif Demir. All rights reserved.
//

#include "MAC.h"
#include <string>
#include <iostream>
using namespace std;
#include "MusicAlbum.h"

MAC :: MAC(){
    musicAlbums = NULL;
    noOfMusicAlbums = 0;
}

MAC :: ~MAC(){
    if(musicAlbums)
        delete[] musicAlbums;
}

MAC :: MAC(const MAC &macToCopy){
    noOfMusicAlbums = macToCopy.getNumberOfMusics();
    if ( noOfMusicAlbums > 0 )
    {
        musicAlbums = new MusicAlbum[ noOfMusicAlbums ];
        for ( int i = 0; i < noOfMusicAlbums; i ++)
        {
            musicAlbums[i] = macToCopy.musicAlbums[i];
        }
    }
    else
    {
        musicAlbums = NULL;
    }
}

void MAC :: operator=(const MAC &right){
    if ( &right != this)
    {
        if ( noOfMusicAlbums != right.noOfMusicAlbums )
        {
            if ( noOfMusicAlbums > 0)
                delete[] musicAlbums;
            noOfMusicAlbums = right.noOfMusicAlbums;
            if ( noOfMusicAlbums > 0)
                musicAlbums = new MusicAlbum[ noOfMusicAlbums ];
            else
                musicAlbums = NULL;
        }
        for ( int i = 0; i < noOfMusicAlbums; i++)
            musicAlbums[i] = right.musicAlbums[i];
    }
}

bool MAC :: addMusicAlbum(string maArtist, string maTitle, int maYear){
    MusicAlbum newAlbum(maArtist, maTitle, maYear);
    if ( musicAlbums == NULL )
    {
        musicAlbums = new MusicAlbum[1];
        musicAlbums[0] = newAlbum;
        noOfMusicAlbums++;
        return true;
    }
    
    else
    {
        for ( int i = 0; i < noOfMusicAlbums; i++)
        {
            if ( ( musicAlbums[i].getMusicAlbumArtist() == maArtist) && ( musicAlbums[i].getMusicAlbumTitle() == maTitle ) )
            {
                return false;
            }
        }
        MusicAlbum * temp = musicAlbums;
        musicAlbums = new MusicAlbum[noOfMusicAlbums + 1];
        for ( int j = 0; j < noOfMusicAlbums; j++ )
        {
            musicAlbums[j] = temp[j];
        }
        musicAlbums[noOfMusicAlbums] = newAlbum;
        noOfMusicAlbums++;
        delete[] temp;
        return true;
    }
}

bool MAC :: removeMusicAlbum(string maArtist, string maTitle){
    for ( int i = 0; i < noOfMusicAlbums; i++)
    {
        if ( musicAlbums[i].getMusicAlbumArtist() == maArtist && musicAlbums[i].getMusicAlbumTitle() == maTitle ){
            MusicAlbum * temp = new MusicAlbum[noOfMusicAlbums-1];
            int deletedNo = 0;
            int tempIndex = 0;
            deletedNo = i;
            for ( int j = 0; j < deletedNo; j++ ){
                temp[tempIndex] = musicAlbums[j];
                tempIndex++;
            }
            
            for ( int k = (deletedNo+1); k < noOfMusicAlbums; k++ ){
                temp[tempIndex] = musicAlbums[k];
                tempIndex++;
            }
            
            noOfMusicAlbums--;
            musicAlbums = new MusicAlbum[noOfMusicAlbums];
            for ( int m = 0; m < noOfMusicAlbums; m++ ){
                musicAlbums[m] = temp[m];
            }
             delete[] temp; // if in icinde mi olmali
        }
    }
    return false;
}

int MAC :: getNumberOfMusics() const{
    return noOfMusicAlbums;
}

int MAC :: getMusicAlbums(MusicAlbum *&allMusicAlbums){
    if ( allMusicAlbums ){
        delete[] allMusicAlbums;
    }
    allMusicAlbums = new MusicAlbum[noOfMusicAlbums];
    for( int i = 0; i < noOfMusicAlbums; i++)
    {
        allMusicAlbums[i] = musicAlbums[i];
    }
    return noOfMusicAlbums;
}

bool MAC :: addSong(const string maArtist, const string maTitle, const string sName, const int sMins, const int sSecs){
    if ( noOfMusicAlbums != 0 ){
        for ( int i = 0; i < noOfMusicAlbums; i++){
            if ( musicAlbums[i].getMusicAlbumArtist() == maArtist && musicAlbums[i].getMusicAlbumTitle() == maTitle)
            {
                musicAlbums[i].createSong( sName, sMins, sSecs);
                return musicAlbums[i].createSong( sName, sMins, sSecs);
            }
        }
    }
    return false;
}

bool MAC :: removeSongs(const string maArtist, const string maTitle){
    if ( noOfMusicAlbums != 0)
    {
        for ( int i = 0; i < noOfMusicAlbums; i++ )
        {
            if ( musicAlbums[i].getMusicAlbumArtist() == maArtist && musicAlbums[i].getMusicAlbumTitle() == maTitle ){
                musicAlbums[i].resetSongList();
                return true;
            }
        }
    }
    return false;
}

void MAC:: calculateAvgMusicAlbumLength(int &minutes,int &seconds){
    int albumsM, albumsS, sumM, sumS;
    sumM = 0;
    sumS = 0;
    if ( noOfMusicAlbums == 0 ){
        minutes = 0;
        seconds = 0;
    }
    else {
        for ( int i = 0; i < noOfMusicAlbums ; i++){
            musicAlbums[i].calculateMusicAlbumLength( albumsM, albumsS);
            sumM = sumM + albumsM;
            sumS = sumS + albumsS;
        }
        sumM *= 60;
        int avg = (sumS + sumM ) / noOfMusicAlbums;
        if( avg > 59 )
        {
            sumM = avg / 60;
            sumS = avg % 60;
        }
        minutes = sumM;
        seconds = sumS;
    }
}
