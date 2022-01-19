#include <bits/stdc++.h>

using namespace std;

struct stak {
private:
    int val;
    int l = 0;
    stak* prev;
    stak* s = nullptr;
public:
    stak () : val(0), l(0), prev(), s(nullptr) {}

    void push_me (int x) {
        stak* n = new stak();
        n->val = x;
        n->prev = s;
        if (s == nullptr)
            n->l = 1;
        else
            n->l = s->l + 1;
        s = n;
    }

    void pop_me () {
        stak* n = s->prev;
        delete s;
        s = n;
    }

    [[nodiscard]] int top_me () const {
        return s->val;
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
            return s->l;
    }

    void clear_me () {
        s->val = 0;
        s->prev = nullptr;
        s = nullptr;
    }
};

signed main () {

    stak rosbinik;
    while (true) {
        string s;
        cin >> s;
        if (s == "push") {
            int n;
            cin >> n;
            rosbinik.push_me(n);
            cout << "ok\n";
        }
        if (s == "pop") {
            if (!rosbinik.empty_me()) {
                cout << rosbinik.top_me() << '\n';
                rosbinik.pop_me();
            } else
                cout << "error\n";
        }
        if (s == "back") {
            if (!rosbinik.empty_me())
                cout << rosbinik.top_me() << '\n';
            else
                cout << "error\n";
        }
        if (s == "clear") {
            if (!rosbinik.empty_me())
                rosbinik.clear_me();
            cout << "ok\n";
        }
        if (s == "size")
            cout << rosbinik.size_me() << '\n';
        if (s == "exit") {
            cout << "bye\n";
            return 0;
        }
    }
}