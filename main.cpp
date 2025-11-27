#include <iostream>
#include <cstring>  
#include <cstdlib>   
#include "queue.h"

using namespace std;

static void getMenu(int id, const char* &name, int &unitPrice) {
    switch (id) {
        case 1: name = "Ramen";         unitPrice = 100; break;
        case 2: name = "Somtum";        unitPrice = 20;  break;
        case 3: name = "Fried Chicken"; unitPrice = 50;  break;
        default: name = "Unknown";      unitPrice = 0;   break;
    }
}

static int askCashUntilEnough(int total) {
    int cash = 0;
    bool first = true;

    do {
        cout << (first ? ":Cash:" : "Cash:");
        cin >> cash;
        first = false;
    } while (cash < total);

    return cash;
}

int main(int argc, char **argv) {
    Queue q;
    int customerNo = 1;

    for (int i = 1; i < argc; i++) {

       
        if (strcmp(argv[i], "x") == 0) {

            
            if (q.isEmpty()) continue;

            int orderId = q.dequeue();
            int qty     = q.dequeue();

            const char* menuName;
            int pricePerUnit;
            getMenu(orderId, menuName, pricePerUnit);

            int total = pricePerUnit * qty;

            cout << "Customer no: " << customerNo << "\n";
            cout << menuName << "\n";
            cout << "You have to pay " << total << "\n";

            int cash = askCashUntilEnough(total);

            cout << "Thank you\n";

            
            int change = cash - total;
            if (change > 0) cout << "Change is:" << change << "\n";

            cout << "========================================\n";
            customerNo++;
        }
       
        else {
            int orderId = atoi(argv[i]);

           
            if (i + 1 < argc && strcmp(argv[i + 1], "x") != 0) {
                int qty = atoi(argv[i + 1]);

                q.enqueue(orderId);
                q.enqueue(qty);

                cout << "My order is " << orderId << "\n";
                i++;
            }
        }
    }

    cout << "There are " << (q.getSize() / 2) << " people left in the queue\n";
    return 0;
}
