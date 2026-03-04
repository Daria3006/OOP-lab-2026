#include <iostream>

using namespace std;

void print_pair(int q, int p) {
    cout << "q = " << q << ", p = " << p << endl;
}

bool prim(int x) {
    for (int d=2; d <= x/2; d++) {
        if (x%d==0) {
            return false;
        }
    }
    return true;
}

bool find_pair(int p) {
    int q;
    q = p + 2;
    if (prim(p) && prim(q)) {
        print_pair(q, p);
        return true;
    }
    return false;
}

void a() {
    int n;
    cout << "a)" << endl;
    cout << "n = ";
    cin >> n;
    int cnt = 1, p =2;
    while (cnt <= n) {
        if (find_pair(p)) {
            cnt ++;
        }
        p++;
    }
}

void print_sequence(int v[100], int start, int end) {
    for (int i = start; i <= end; i++) {
        cout << v[i] << " ";
    }
}

void get_longest(int n, int v[100]) {
    int len = 1, max_len = 0, start = 1, max_start, max_end;
    for (int i = 2; i <= n; i++) {
        if (v[i] < v[i - 1]) {
            len++;
            if (len > max_len) {
                max_len = len;
                max_start = start;
                max_end = i;
            }
        } else {
            len = 1;
            start = i;
        }
    }
    print_sequence(v, max_start, max_end);
}

void b() {
    int n, v[101];
    cout << "b)" << endl;
    cout << "n = ";
    cin >> n;
    cout << endl << "Enter numbers: ";
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    get_longest(n, v);
}

int main() {
    a();
    b();
    return 0;
}
