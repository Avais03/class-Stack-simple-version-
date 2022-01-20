/**
 *    author:  VladimirSlastin
 *    created: 19.01.2022.
 *    C++20
**/
#include <iostream>

class stak {
private:
    int value;
    int size = 0;
    stak* prev;
    stak* s = nullptr;
public:
    stak () : value(0), size(0), prev(), s(nullptr) {}

    void push_me (int x) {
        stak* n = new stak();
        n->value = x;
        n->prev = s;
        if (s == nullptr)
            n->size = 1;
        else
            n->size = s->size + 1;
        s = n;
    }

    void pop_me () {
        stak* n = s->prev;
        delete s;
        s = n;
    }

    [[nodiscard]] int top_me () const {
        return s->value;
    }

    [[nodiscard]] bool empty_me () const {
        if (s == nullptr)
            return true;
        else
            return false;
    }

    [[nodiscard]] int size_me () const {
        if (s == nullptr)
            return 0;
        else
            return s->size;
    }

    void clear_me () {
        s->value = 0;
        s->prev = nullptr;
        s = nullptr;
    }
};

signed main () {

    stak rosbinik;
    while (true) {
        std::string s;
        std::cin >> s;
        if (s == "push") {
            int n;
            std::cin >> n;
            rosbinik.push_me(n);
            std::cout << "ok\n";
        }
        if (s == "pop") {
            if (!rosbinik.empty_me()) {
                std::cout << rosbinik.top_me() << '\n';
                rosbinik.pop_me();
            } else
                std::cout << "error\n";
        }
        if (s == "back") {
            if (!rosbinik.empty_me())
                std::cout << rosbinik.top_me() << '\n';
            else
                std::cout << "error\n";
        }
        if (s == "clear") {
            if (!rosbinik.empty_me())
                rosbinik.clear_me();
            std::cout << "ok\n";
        }
        if (s == "size")
            std::cout << rosbinik.size_me() << '\n';
        if (s == "exit") {
            std::cout << "bye\n";
            return 0;
        }
    }
}
