#include "PhoneBook.hpp"

int	PhoneBook::get_size(void) const {
	return (this->size);
}

void	PhoneBook::add_contact(std::string data[5]) {
	int	index;

	index = this->index;
	this->contacts[index].set_firstname(data[0]);
	this->contacts[index].set_lastname(data[1]);
	this->contacts[index].set_nickname(data[2]);
	this->contacts[index].set_number(data[3]);
	this->contacts[index].set_secret(data[4]);
	this->index = (index + 1) % 8;

	if (this->size < 8)
		this->size++;
}

void	PhoneBook::display_contact(int index) const {
	std::cout << "First Name: " << this->contacts[index].get_firstname() << std::endl;
	std::cout << "Last Name: " << this->contacts[index].get_lastname() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].get_nickname() << std::endl;
	std::cout << "Phone Number: " << this->contacts[index].get_number() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[index].get_secret() << std::endl;
}

void	PhoneBook::display_phonebook(void) const {
	for (int i = 0; i < this->size; i++) {
		std::cout << "|" << i << "\t|";
		std::cout << "\t" << this->contacts[i].get_firstname() << "|";
		std::cout << "\t" << this->contacts[i].get_lastname() << "|";
		std::cout << "\t" << this->contacts[i].get_nickname() << "|" << std::endl;
	}
}
