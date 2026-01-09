// Alan Guerrero
// CosmeticSalesReport.cpp
/*
   Program: Cosmetic Sales Report
   This program manages and generates reports for a cosmetics inventory.
   The main challenge was implementing the filtering and reporting functionality while maintaining clean code.
   I accomplished the solution by breaking down the tasks into manageable functions for displaying the report, calculating sales totals and averages, and filtering data by category and price.
   I received no external help and relied on my own understanding of C++ and the requirements of the task.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
void displayReport(string pn[], double pp[], int pq[], char pc[]);
double findTotalSales(double pp[], int pq[]);
double findAverageSales(double pp[], int pq[]);
void productHeader();
void productDetailLine(string pn, double pp, int pq, char pc);
void productFooter(double totalSales, double averageSales);
void categoryReport(char c, string pn[], double pp[], int pq[], char pc[]);
void priceReport(double maxPrice, string pn[], double pp[], int pq[], char pc[]);

int main() {
    // Product data (arrays)
    string productName[] = {
        "Lipstick", "Foundation", "Mascara", "Eyeshadow", "Blush",
        "Eyeliner", "Nail Polish", "Bronzer", "Highlighter", "Concealer",
        "Moisturizer", "Cleanser", "Face Serum", "Shampoo", "Conditioner",
        "Body Lotion", "Hand Cream", "Sunscreen", "Body Wash", "Shaving Cream"
    };

    double productPrice[] = {
        12.99, 24.99, 18.99, 22.99, 16.49,
        14.99, 9.99, 21.99, 19.99, 17.49,
        8.99, 10.99, 29.99, 11.49, 12.49,
        6.99, 7.49, 15.99, 5.99, 4.99
    };

    int productQuantity[] = {
        100, 150, 200, 120, 130,
        110, 180, 140, 160, 200,
        250, 220, 90, 190, 210,
        300, 350, 50, 400, 500
    };

    char productCategory[] = {
        'F', 'F', 'F', 'F', 'F',
        'F', 'F', 'F', 'F', 'F',
        'S', 'S', 'S', 'H', 'H',
        'B', 'B', 'S', 'S', 'S'
    };

    // Menu
    int choice;
    char category;
    double maxPrice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Display Report of data in original order with header and footer" << endl;
        cout << "2. Display Report of data in original order based on a category (filter)" << endl;
        cout << "3. Display Report of data in original order based on a price (filter)" << endl;
        cout << "4. End Program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayReport(productName, productPrice, productQuantity, productCategory);
            break;
        case 2:
            cout << "Enter category to filter by (F, S, H, B): ";
            cin >> category;
            categoryReport(category, productName, productPrice, productQuantity, productCategory);
            break;
        case 3:
            cout << "Enter maximum price to filter by: ";
            cin >> maxPrice;
            priceReport(maxPrice, productName, productPrice, productQuantity, productCategory);
            break;
        case 4:
            cout << "Ending Program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

// Function to display the full report
void displayReport(string pn[], double pp[], int pq[], char pc[]) {
    productHeader();
    for (int i = 0; i < 20; i++) {
        productDetailLine(pn[i], pp[i], pq[i], pc[i]);
    }
    double totalSales = findTotalSales(pp, pq);
    double averageSales = findAverageSales(pp, pq);
    productFooter(totalSales, averageSales);
}

// Function to calculate total sales
double findTotalSales(double pp[], int pq[]) {
    double total = 0;
    for (int i = 0; i < 20; i++) {
        total += pp[i] * pq[i];
    }
    return total;
}

// Function to calculate average sales
double findAverageSales(double pp[], int pq[]) {
    double totalSales = findTotalSales(pp, pq);
    return totalSales / 20;
}

// Function to print the report header
void productHeader() {
    cout << setw(20) << left << "Product" << setw(10) << "Price" << setw(10) << "Qty"
        << setw(10) << "Category" << setw(10) << "Ext. Price" << endl;
    cout << "-------------------------------------------------------------" << endl;
}

// Function to print a product's details in the report
void productDetailLine(string pn, double pp, int pq, char pc) {
    double extPrice = pp * pq;
    cout << setw(20) << left << pn
        << setw(10) << fixed << setprecision(2) << pp
        << setw(10) << pq
        << setw(10) << pc
        << setw(10) << extPrice << endl;
}

// Function to print the report footer
void productFooter(double totalSales, double averageSales) {
    cout << "-------------------------------------------------------------" << endl;
    cout << "Average Sales: " << fixed << setprecision(2) << averageSales << endl;
    cout << "Total Sales: " << fixed << setprecision(2) << totalSales << endl;
}

// Function to display a report for a specific category
void categoryReport(char c, string pn[], double pp[], int pq[], char pc[]) {
    productHeader();
    for (int i = 0; i < 20; i++) {
        if (pc[i] == c) {
            productDetailLine(pn[i], pp[i], pq[i], pc[i]);
        }
    }
    double totalSales = findTotalSales(pp, pq);
    double averageSales = findAverageSales(pp, pq);
    productFooter(totalSales, averageSales);
}

// Function to display a report for products below a certain price
void priceReport(double maxPrice, string pn[], double pp[], int pq[], char pc[]) {
    productHeader();
    for (int i = 0; i < 20; i++) {
        if (pp[i] <= maxPrice) {
            productDetailLine(pn[i], pp[i], pq[i], pc[i]);
        }
    }
    double totalSales = findTotalSales(pp, pq);
    double averageSales = findAverageSales(pp, pq);
    productFooter(totalSales, averageSales);
}
