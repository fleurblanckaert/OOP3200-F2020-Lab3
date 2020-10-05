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

	//Initializes all inherited attributes and sets isOpen attribute to true
	ExtendedWorkTicket() : WorkTicket(), isOpen(true) {}

	//Sets base class parameterized constructor's parameters and adds it's own parameter is_open
	ExtendedWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool is_open);

	//Gets the isOpen value
	bool IsOpen() const;

	//Sets isOpen to false and closes the ticket
	void CloseTicket();

	//Calls base class SetWorkTicket + adding isOpen attribute
	bool SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string&
		description, bool is_open);
	
	//Overrides base class ShowWorkTicket to display attributes + indicate if ticket is open
	virtual void ShowWorkTicket() const override;

	//Displays object's attributes 
	friend ostream& operator<<(ostream& out, const ExtendedWorkTicket& ticket);


private:

	//Indicates whether the class is open or close
	bool isOpen;
};

//Sets values to the parameterized constructor using the base class's attributes and isOpen
inline ExtendedWorkTicket::ExtendedWorkTicket(int ticket_number, const std::string& client_id, int day, int month, int year, const std::string& description, bool is_open)
	: WorkTicket(ticket_number, client_id, day, month, year, description), isOpen(std::move(is_open)) {}

//Sets IsOpen
inline bool ExtendedWorkTicket::IsOpen() const { return isOpen; }

//Sets CloseTicket
inline void  ExtendedWorkTicket::CloseTicket() { isOpen = false; }

//Sets isOpen to user input and base class's attributes if a work ticket is valid else it returns false
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

//Displays work ticket contents by overriding show work ticket from the base class and adding messages based on the isOpen attribute
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

//Displays work ticket contents by typecasting the object as a WorkTicket and adding messages based on the isOpen attribute 
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