/**
 * Name: Fleur Blanckaert (100747083), Gabriel Dietrich ()
 * Class: OOP 3200
 * Description: A class that 
 */

#pragma once

#ifndef _EXTENDED_WORK_TICKET
#define _EXTENDED_WORK_TICKET
#include "WorkTicket.h"
#include <string>

class ExtendedWorkTicket : public WorkTicket {

public:
	ExtendedWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool isOpen);
	
};


#endif //__EXTENDED_WORK_TICKET
