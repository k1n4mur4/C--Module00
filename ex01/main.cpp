#include "PhoneBook.hpp"
#include <string>
#include <cctype>

static bool	is_valid_number(const std::string& number) {
	std::string::size_type	len;

	len = number.length();
	if (len != 10)
		return (false);
	for (std::string::size_type i = 0; i < len; ++i) {
		if (!std::isdigit(static_cast<unsigned char>(number[i]))) {
			return (false);
		}
	}
	return (true);
}

void	command_add(PhoneBook& phonebook) {
	std::string	data[5];

	std::cout << "First Name: ";
	std::getline(std::cin, data[0]);
	std::cout << "Last Name: ";
	std::getline(std::cin, data[1]);
	std::cout << "Nickname: ";
	std::getline(std::cin, data[2]);
	while (true) {
		std::cout << "Phone Number: ";
		if (!std::getline(std::cin, data[3]))
			return ;
		if (is_valid_number(data[3]))
			break ;
		std::cout << data[3] << " is not a valid phone number" << std::endl;
	}
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, data[4]);
	phonebook.add_contact(data);
	std::cout << "Contact added successfully" << std::endl;
}

void	command_search(PhoneBook &phonebook) {
	int			index;
	std::string	input;

	phonebook.display_phonebook();
	std::cout << "Index: ";
	std::getline(std::cin, input);
	index = std::atoi(input.c_str());
	if (index < 0 || index >= phonebook.get_size()) {
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	phonebook.display_contact(index);
}

int	main(void) {
	PhoneBook	phonebook;
	std::string	input;

	while (true) {
		std::cout << "Phonebook ";
		std::getline(std::cin, input);
		if (input == "ADD") {
			command_add(phonebook);
		}
		else if (input == "SEARCH") {
			command_search(phonebook);
		}
		else if (input == "EXIT") {
			std::cout << "Exiting Phonebook" << std::endl;
			break;
		}
		else
			std::cout << input << " is not a valid command" << std::endl;
	}
	return 0;
}
