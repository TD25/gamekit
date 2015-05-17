/*
 * 
-------------------------------------------------------------------------------
    This file is part of OgreKit.
    http://gamekit.googlecode.com/

    Copyright (c) 2015 Tadas V.

    Contributor(s): none yet
-------------------------------------------------------------------------------
  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/
#ifndef _gkStackFSM_h_
#define _gkStackFSM_h_

#include "gkCommon.h"

/**
 * FSM class, where state functions are stored in a stack and called in
 * update method.
 * State functions should perform action for that state and 
 * set state if needed (by poping itself from a stack or pushing new
 * state or combination of both).
 */
class gkStackFSM
{
public:
	gkStackFSM() {};
	~gkStackFSM() {};
	
	void update()
	{
		void * state = getState();
		if (state)
			state();
	}
	void pushState(void(*stateFunction)(void));
	{
		UT_ASSSERT(stateFunction != nullptr)
		m_states.push(stateFunction);
	}
	void* popState()
	{
		UT_ASSSERT(m_states.size() > 0)
		return m_states.pop();
	}		
	void* getState()
	{
		if (!mStates.size)
			return nullptr;
		return m_states.top();
	}
private:
	utStack<void*(void)> m_states;
	
};


#endif//gkStackFSM_h
