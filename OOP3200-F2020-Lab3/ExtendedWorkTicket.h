/* Name: Fleur Blanckaert (100747083), Gabriel Dietrich (100764733)
   Date: October 4th, 2020
   Program: Lab 3 - Inheritance
   Description: A class that extends the WorkTicket class and
 *				indicates the status of the work ticket in terms of it
 *				being open or closed
 */

#pragma once

#ifndef _EXTENDED_WORK_TICKET
#define _EXTENDED_WORK_TICKET

#include "WorkTicket.h"
#include <string>


class ExtendedWorkTicket : public WorkTicket {


public:

	// Default constructor
	ExtendedWorkTicket() : WorkTicket(), isOpen(true) {}

	// Parameterized constructor
	ExtendedWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool is_open);

	// Accessor to get isOpen value
	bool IsOpen() const;

	// Mutator to close ticket
	void CloseTicket();

	// Calling base class SetWorkTicket + adding isOpen attribute
	bool SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string&
		description, bool is_open);
	
	// Overriding base class ShowWorkTicket to display attributes + indicate if ticket is open
	virtual void ShowWorkTicket() const override;

	//Out stream operator
	friend ostream& operator<<(ostream& out, const ExtendedWorkTicket& ticket);


private:
	bool isOpen;


};

inline ExtendedWorkTicket::ExtendedWorkTicket(int ticket_number, const std::string& client_id, int day, int month, int year, const std::string& description, bool is_open)
	: WorkTicket(ticket_number, client_id, day, month, year, description), isOpen(std::move(is_open)) {}

// Accessor to get isOpen value
inline bool ExtendedWorkTicket::IsOpen() const { return isOpen; }

// Mutator to close ticket
inline void  ExtendedWorkTicket::CloseTicket() { isOpen = false; }

bool ExtendedWorkTicket::SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool is_open)
{
	bool isValid = true;

	if (!WorkTicket::SetWorkTicket(ticket_number, client_id, day, month, year, description))
	{
		isValid = false;
	}
	else
	{
		isOpen = is_open;
		isValid = true;
	}

	return isValid;

}

//Accessor to show work ticket contents
void ExtendedWorkTicket::ShowWorkTicket() const
{
	WorkTicket::ShowWorkTicket();

	if (isOpen == true)
	{
		cout << "Ticket:        Open" << endl;
	}
	else
	{
		cout << "Ticket:        Close" << endl;
	}
}

//
ostream& operator<<(ostream& out, const ExtendedWorkTicket& ticket)
{
	out << (WorkTicket)ticket;

	if (ticket.IsOpen() == true)
	{
		out << "Ticket:        Open";

	}
	else
	{
		out << "Ticket:        Close";
	}
	
	return out;
}

#endif //__EXTENDED_WORK_TICKET