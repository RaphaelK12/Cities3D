/*
 *  Cities3D - Copyright (C) 2001-2009 Jason Fugate (saladyears@gmail.com)
 * 
 *  This program is free software; you can redistribute it and/or modify it 
 *  under the terms of the GNU General Public License as published by the Free 
 *  Software Foundation; either version 2 of the License, or (at your option) 
 *  any later version.
 * 
 *  This program is distributed in the hope that it will be useful, but 
 *  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 *  or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License 
 *  for more details.
 */
#pragma once

#include "style.h"	//READ THIS BEFORE MAKING ANY CHANGES TO THIS FILE!!!

//---------------------------- SYSTEM INCLUDES  -----------------------------//

//---------------------------- USER INCLUDES    -----------------------------//

//---------------------------- DEFINES          -----------------------------//

//---------------------------- TYPEDEFS         -----------------------------//
class wxSocketServer;

//---------------------------- CLASSES          -----------------------------//

//---------------------------------------------------------------------------//
// Class: wxLocalServerThread
// 
// A server worker thread for handling connections from other instances of
// CitiesOnline.
//
// Derived From:
//     wxThread
//
// Project:
//     <CitiesOnline>
//
// Include:
//     LocalServerThread.h
//
class wxLocalServerThread : public wxThread
{
	//-----------------------------------------------------------------------//
	// Section: Private
	//
private:
	//-----------------------------------------------------------------------//
	// Group: Virtual Functions
	//

	//-----------------------------------------------------------------------//
	// Function: Entry
	//
	// The entry point of the thread where it does all of its work.
	//
	// Returns:
	//     A NULL pointer.
	//
	virtual void* Entry();

	//-----------------------------------------------------------------------//
	// Function: OnExit
	//
	// Handles cleanup when the thread exits.
	//
	virtual void OnExit();

	//-----------------------------------------------------------------------//
	// Group: Variables
	//

	//-----------------------------------------------------------------------//
	// Pointer: mServer
	//
	// The socket server.
	//
	boost::scoped_ptr<wxSocketServer> mpLocalServer;
};

//---------------------------- PROTOTYPES       -----------------------------//

