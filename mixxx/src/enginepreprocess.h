/***************************************************************************
                          enginepreprocess.h  -  description
                             -------------------
    begin                : Mon Feb 3 2003
    copyright            : (C) 2003 by Tue and Ken Haste Andersen
    email                : 
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef ENGINEPREPROCESS_H
#define ENGINEPREPROCESS_H

#include "engineobject.h"
#include "defs.h"
#include <qptrlist.h>

class EngineSpectralFwd;
class WindowKaiser;
class SoundBuffer;

/**
  * Pre-processing of audio buffers before playback and handling by EngineBuffer::process()
  *
  *@author Tue and Ken Haste Andersen
  */

class EnginePreProcess : public EngineObject
{
public:
    EnginePreProcess(SoundBuffer *_soundbuffer, int _specNo, WindowKaiser *window);
    ~EnginePreProcess();
    void notify(double) {};
    void update(int specFrom, int specTo);
    CSAMPLE *process(const CSAMPLE *, const int);
private:
    void process(int idx);

    SoundBuffer *soundbuffer;
    int specNo;
    QPtrList<EngineSpectralFwd> specList;
    CSAMPLE *hfc;    
};

#endif
