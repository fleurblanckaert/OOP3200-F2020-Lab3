/* Name: Fleur Blanckaert(100747083), Gabriel Dietrich(100764733)
   Date : October 4th, 2020
   Program : Lab 3 - Inheritance
 * Description: A class that extends the WorkTicket class and
 *				indicates the status of the work ticket in terms of it
 *				being open or closed
 */

#include "ExtendedWorkTicket.h"

inline ExtendedWorkTicket::ExtendedWorkTicket() : WorkTicket(), myIsOpen(true) {}

inline ExtendedWorkTicket::ExtendedWorkTicket(int ticket_number, const std::string& client_id, int day, int month, int year, const std::string& description, bool is_open)
	: WorkTicket(ticket_number, client_id, day, month, year, description), myIsOpen(std::move(is_open)) {}

// Accessor to get isOpen value
inline bool ExtendedWorkTicket::IsOpen() const { return myIsOpen; }

// Mutator to close ticket
inline void  ExtendedWorkTicket::CloseTicket() { myIsOpen = false; }

bool ExtendedWorkTicket::SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool is_open)
{
	bool isValid = true;

	if (!WorkTicket::SetWorkTicket(ticket_number, client_id, day, month, year, description))
	{
		isValid = false;
	}
	else
	{
		isValid = true;
	}

	return isValid;

}

//Accessor to show work ticket contents
void ExtendedWorkTicket::ShowWorkTicket() const
{
	WorkTicket::ShowWorkTicket();

	if (myIsOpen == true)
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

