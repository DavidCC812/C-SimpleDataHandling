#include <iostream>
#include "Entity.hpp"
#include "BinarySearchTree.hpp"

int main() {
	BinarySearchTree<Entity> bst;

	int choice;
	do {
		std::cout << "1. Insert Entity\n2. Search Entity\n3. Remove Entity\n4. Display All Entities\n5. Exit\n";
		std::cout << "Enter choice: ";
		std::cin >> choice;

		switch (choice) {
			case 1: {
				std::string name;
				int id;
				std::cout << "Enter name: ";
				std::cin >> name;
				std::cout << "Enter ID: ";
				std::cin >> id;
				bst.insert(Entity(name, id));
				break;
			}
			case 2: {
				int id;
				std::cout << "Enter ID to search: ";
				std::cin >> id;
				if (bst.search(Entity("", id))) {
					std::cout << "Entity found!\n";
				} else {
					std::cout << "Entity not found.\n";
				}
				break;
			}
			case 3: {
				int id;
				std::cout << "Enter ID to remove: ";
				std::cin >> id;
				bst.remove(Entity("", id));
				break;
			}
			case 4:
				std::cout << "Entities in BST:\n";
				bst.inOrderTraversal();
				break;
			case 5:
				std::cout << "Exiting...\n";
				break;
			default:
				std::cout << "Invalid choice. Try again.\n";
		}
	} while (choice != 5);

	return 0;
}
