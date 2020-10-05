
/* Name: Fleur Blanckaert (100747083), Gabriel Dietrich (100764733)
   Date: October 4th, 2020
   Program: Lab 3 - Inheritance
   Description: This file displays the default data created in WorkTicket and the
				inherited class ExtendedWorkTicket
*/
#include <iostream>

#include "ExtendedWorkTicket.h"

int main()
{
	// Creates two ticket numbers
	ExtendedWorkTicket testTicket1;
	ExtendedWorkTicket testTicket2(1, "AMCE_123", 1, 7, 2014, "Password Reset", true);


	// Displays both tickets created
	std::cout << std::endl << "As Initialized: " << std::endl;
	testTicket1.ShowWorkTicket();
	testTicket2.ShowWorkTicket();

	//Sets new values to ticket 1
	if (!testTicket1.SetWorkTicket(2, "MACDONALD-001", 10, 3, 2012, "User cannot locate \'any\' key.", true))
		std::cout << "\nErrors! No changes to the ticket made." << std::endl;

	std::cout << std::endl << "Ticket 1: " << testTicket1 << std::endl;

	//Displays an error because values set are not valid
	if (!testTicket2.SetWorkTicket(-1, "BLAGO-042", 13, 32, 11, "", false))
		std::cout << "\nErrors! No changes to the ticket made." << std::endl;

	std::cout << std::endl << "Ticket 2: " << testTicket2 << std::endl;

	//Closes ticket 2
	testTicket2.CloseTicket();

	//Displays ticket 2 isOpen value after it was closed
	std::cout << std::endl << "After Ticket 2 closed: " << testTicket2 << std::endl;

	std::cout << std::endl << std::endl;
	return 0;
}




