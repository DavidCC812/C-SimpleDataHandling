#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Product {
public:
	int id;
	string name;
	double price;
	int stock;

	Product(int id, string name, double price, int stock)
		: id(id), name(name), price(price), stock(stock) {}
};

void addProduct(vector<Product>& products);
void retrieveProduct(const vector<Product>& products);
void updateProduct(vector<Product>& products);
void removeProduct(vector<Product>& products);
void displayProducts(const vector<Product>& products);
void mergeSort(vector<Product>& products, int left, int right);
void merge(vector<Product>& products, int left, int mid, int right);
int binarySearch(const vector<Product>& products, int id);

int main() {
	vector<Product> products;
	int choice;

	do {
		cout << "\n--- Product Management Menu ---\n";
		cout << "1. Add Product\n";
		cout << "2. Retrieve Product\n";
		cout << "3. Update Product\n";
		cout << "4. Remove Product\n";
		cout << "5. Display All Products\n";
		cout << "6. Sort Products by Price\n";
		cout << "7. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			addProduct(products);
			break;
		case 2:
			retrieveProduct(products);
			break;
		case 3:
			updateProduct(products);
			break;
		case 4:
			removeProduct(products);
			break;
		case 5:
			displayProducts(products);
			break;
		case 6:
			mergeSort(products, 0, products.size() - 1);
			cout << "Products sorted by price.\n";
			break;
		case 7:
			cout << "Exiting...\n";
			break;
		default:
			cout << "Invalid choice. Try again.\n";
		}
	} while (choice != 7);

	return 0;
}

void addProduct(vector<Product>& products) {
	int id, stock;
	double price;
	string name;

	cout << "Enter Product ID: ";
	cin >> id;
	cin.ignore(); 
	cout << "Enter Product Name: ";
	getline(cin, name);
	cout << "Enter Product Price: ";
	cin >> price;
	cout << "Enter Product Stock: ";
	cin >> stock;

	products.emplace_back(id, name, price, stock);
	cout << "Product added successfully!\n";
}

void retrieveProduct(const vector<Product>& products) {
	int id;
	cout << "Enter Product ID to retrieve: ";
	cin >> id;

	int index = binarySearch(products, id);
	if (index != -1) {
		cout << "Product Found: ID=" << products[index].id
			<< ", Name=" << products[index].name
			<< ", Price=" << products[index].price
			<< ", Stock=" << products[index].stock << endl;
	} else {
		cout << "Product not found.\n";
	}
}

void updateProduct(vector<Product>& products) {
	int id;
	cout << "Enter Product ID to update: ";
	cin >> id;

	int index = binarySearch(products, id);
	if (index != -1) {
		cout << "Enter new Product Name: ";
		cin.ignore(); 
		getline(cin, products[index].name);
		cout << "Enter new Product Price: ";
		cin >> products[index].price;
		cout << "Enter new Product Stock: ";
		cin >> products[index].stock;
		cout << "Product updated successfully!\n";
	} else {
		cout << "Product not found.\n";
	}
}


void removeProduct(vector<Product>& products) {
	int id;
	cout << "Enter Product ID to remove: ";
	cin >> id;

	int index = binarySearch(products, id);
	if (index != -1) {
		products.erase(products.begin() + index);
		cout << "Product removed successfully!\n";
	} else {
		cout << "Product not found.\n";
	}
}


void displayProducts(const vector<Product>& products) {
	if (products.empty()) {
		cout << "No products available.\n";
		return;
	}

	cout << "ID\tName\t\tPrice\tStock\n";
	for (const Product& product : products) {
		cout << product.id << "\t" << product.name << "\t\t"
			<< product.price << "\t" << product.stock << endl;
	}
}


void mergeSort(vector<Product>& products, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(products, left, mid);
		mergeSort(products, mid + 1, right);
		merge(products, left, mid, right);
	}
}

void merge(vector<Product>& products, int left, int mid, int right) {
	vector<Product> temp;
	int i = left, j = mid + 1;

	while (i <= mid && j <= right) {
		if (products[i].price <= products[j].price) {
			temp.push_back(products[i]);
			i++;
		} else {
			temp.push_back(products[j]);
			j++;
		}
	}

	while (i <= mid) {
		temp.push_back(products[i]);
		i++;
	}
	while (j <= right) {
		temp.push_back(products[j]);
		j++;
	}

	for (int k = left; k <= right; k++) {
		products[k] = temp[k - left];
	}
}

int binarySearch(const vector<Product>& products, int id) {
	int left = 0, right = products.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (products[mid].id == id) {
			return mid;
		} else if (products[mid].id < id) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return -1;
}
