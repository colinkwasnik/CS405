// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <limits>

int main()
{
	std::cout << "Buffer Overflow Example" << std::endl;

	const std::string account_number = "CharlieBrown42";
	char user_input[20];

	std::cout << "Enter a value (max 19 characters): ";
	std::cin.get(user_input, sizeof(user_input)); // Read up to 19 characters

	// Check if input exceeded buffer limit
	if (std::cin.peek() != '\n' && !std::cin.eof()) {
		std::cout << "Warning: Input too long. Extra characters discarded." << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard rest of the line
	}

	std::cout << "You entered: " << user_input << std::endl;
	std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
