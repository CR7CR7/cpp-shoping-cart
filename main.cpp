#include <iostream>
#include <vector>
#include "datamodel.h"

// Declare the product list here (global to main.cpp)
std::vector<Product> products = {
    Product(1, "Apple", 2.80),
    Product(2, "Mango", 5.50),
    Product(3, "Guava", 6.20),
    Product(4, "Banana", 1.90),
    Product(5, "Strawberry", 8.50),
    Product(6, "Pineapple", 7.20)
};

int main()
{
    Cart cart;

    int choice, qty;
    bool running = true;

    std::cout << "Welcome to the Online Shopping App!\n";

    while (running) {
        std::cout << "\nChoose product to add:\n";

        for (const auto& p : products) {
            std::cout << p.id << ". " << p.getDisplayName();
        }

        std::cout << "7. Apply coupon\n";
        std::cout << "8. Checkout\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 6) {
            std::cout << "Quantity: ";
            std::cin >> qty;
            cart.addItem(products[choice - 1], qty);
        }
        else if (choice == 7) {
            int percent;
            std::cout << "Enter coupon percent (e.g. 10 for 10%): ";
            std::cin >> percent;
            cart.applyCoupon(percent);
        }
        else if (choice == 8) {
            running = false;
        }
        else {
            std::cout << "Invalid choice.\n";
        }
    }

    cart.printCart();
    return 0;
}
