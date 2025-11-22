#include <iostream>
using namespace std;

#include "stack.h"

int main(int argc, char **argv) {

    cout << "Checking the parentheses in argv arguments\n";

    for (int i = 1; i < argc; i++) {
        Stack s;
        bool ok = true;

        for (int j = 0; argv[i][j] != '\0'; j++) {
            char c = argv[i][j];

            // เจอวงเล็บเปิด → push
            if (c == '[' || c == '{') {
                s.push(c);
            }
            else if (c == ']' || c == '}') {

                if (s.isEmpty()) {
                    ok = false;
                    break;
                }

                char x = s.pop();   

                // คู่ไม่ตรงกัน
                if ((c == ']' && x != '[') ||
                    (c == '}' && x != '{')) {
                    ok = false;
                    break;
                }
            }
        }

        if (!s.isEmpty()) {
            ok = false;
        }

        if (ok) {
            cout << "correct" << endl;
        } else {
            cout << "incorrect" << endl;
        }
    }

    return 0;
}
