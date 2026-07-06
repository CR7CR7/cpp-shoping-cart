#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

class Product {
public:
    int id;
    std::string name;
    double price;   // <-- FIX: double instead int

    Product(int u_id, const std::string& name, double price)
        : id(u_id), name(name), price(price) {}

    std::string getDisplayName() const {
        std::ostringstream ss;
        ss << name << " : $ " << std::fixed << std::setprecision(2) << price << "\n";
        return ss.str();
    }
};

class Item {
public:
    Product product;
    int quantity;

    Item(const Product& p, int qty)
        : product(p), quantity(qty) {}

    double getTotalPrice() const {
        return product.price * quantity;
    }
};

class Cart {
private:
    std::vector<Item> items;
    int couponPercent = 0;

public:
    void addItem(const Product& p, int qty) {
        items.emplace_back(p, qty);
    }

    void applyCoupon(int percent) {
        if (percent < 0 || percent > 100) {
            std::cout << "Invalid coupon. Must be between 0 and 100.\n";
            return;
        }
        couponPercent = percent;
    }

    double getTotal() const {
        double total = 0.0;

        for (const auto& item : items)
            total += item.getTotalPrice();

        if (couponPercent > 0)
            total -= (total * couponPercent) / 100.0;

        return total;
    }

    void printCart() const {
        std::cout << "\n--- Shopping Cart ---\n";

        for (const auto& item : items) {
            std::cout << item.product.name << " : $ "
                      << std::fixed << std::setprecision(2) << item.product.price << "\n";

            std::cout << "Qty: " << item.quantity
                      << " | Subtotal: $ "
                      << std::fixed << std::setprecision(2)
                      << item.getTotalPrice() << "\n";
        }

        if (couponPercent > 0)
            std::cout << "Coupon applied: -" << couponPercent << "%\n";

        std::cout << "TOTAL: $ "
                  << std::fixed << std::setprecision(2)
                  << getTotal() << "\n";
    }
};

#endif
