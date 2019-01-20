//
//  Song.cpp
//  HW_1_B
//
//  Created by Elif Demir on 18.11.2018.
//  Copyright © 2018 Elif Demir. All rights reserved.
//
#include "Song.h"
#include <string>
using namespace std;

Song :: Song( const string sName, const int sMins, const int sSecs)
{
    name = sName;
    mins = sMins;
    secs = sSecs;
}

Song :: ~Song() {
}

Song :: Song( const Song &songToCopy) {
    if ( &songToCopy != this ){
        name = songToCopy.name;
        mins = songToCopy.mins;
        secs = songToCopy.secs;
    }
}

void Song :: operator =(const Song &right)
{
    if ( &right != this ) {
        name = right.name;
        mins = right.mins;
        secs = right.secs;
    }
}

string Song :: getName(){
    return name;
}

int Song :: getSecs(){
    return secs;
}

int Song :: getMins(){
    return mins;
}
