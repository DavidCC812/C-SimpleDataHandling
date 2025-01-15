#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <iostream>

class Entity {
public:
	std::string name;
	int id;

	Entity(std::string name = "", int id = 0)
		: name(name), id(id) {}

	bool operator<(const Entity& other) const {
		return id < other.id;
	}

	bool operator>(const Entity& other) const {
		return id > other.id;
	}

	bool operator==(const Entity& other) const {
		return id == other.id;
	}

	friend std::ostream& operator<<(std::ostream& os, const Entity& e) {
		os << "ID: " << e.id << ", Name: " << e.name;
		return os;
	}
};

#endif
