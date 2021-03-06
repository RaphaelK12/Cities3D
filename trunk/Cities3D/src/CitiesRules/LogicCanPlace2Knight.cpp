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
#include "stdwx.h"
#include "style.h"	//READ THIS BEFORE MAKING ANY CHANGES TO THIS FILE!!!

//---------------------------- SYSTEM INCLUDES  -----------------------------//

//---------------------------- USER INCLUDES    -----------------------------//
#include "Logic.h"
#include "RuleSetDatabase.h"
#include "KnightObject.h"
#include "IRuleEngine.h"

//---------------------------- TYPEDEFS         -----------------------------//
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//---------------------------- STATICS          -----------------------------//

//---------------------------- LOGIC            -----------------------------//

//---------------------------------------------------------------------------//
// Class: LogicCanPlace2Knight
// 
// Determines the available board locations for a strong knight to replace a
// basic knight.
//
// Derived From:
//     <Logic>
//
// Project:
//     <CitiesRules>
//
// RuleSet:
//     <Cities>
//
class LogicCanPlace2Knight : public Logic
{
public:
	virtual void Decide(const DataObject &, DataObject &output)
	{
		PlayerGame::CornerObjectArray available;

		// A player can upgrade any knight that is strength 1.
		const PlayerGame::CornerObjectArray& knights =
			playerGame().getCornerObjects(shKnights);

		PlayerGame::CornerObjectArray::const_iterator it, itEnd = knights.end();
		for(it = knights.begin(); it != itEnd; ++it)
		{
			KnightObject* object = static_cast<KnightObject*>((*it).get());
			if(1 == object->strength())
			{
				available.push_back((*it));
			}
		}

		// Return the final placement selections.
		output = DataObject(available);
	}
};

IMPLEMENT_LOGIC(LogicCanPlace2Knight, CITIES)
