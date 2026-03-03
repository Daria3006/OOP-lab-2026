//
// Created by user on 02.03.2026.
//
#include <iostream>

using namespace std;

void print_decompose(int d, int cnt) {
    cout << d << " ^ " << cnt << endl;
}

void decompose(int n) {
    int cnt = 0,d = 2;
    while (n > 1) {
        if (n % d == 0) {
            n /= d;
            cnt++;
        }
        else {
            if (cnt != 0)
                print_decompose(d, cnt);
            cnt = 0;
            if (d % 2 == 0) {
                d++;
            }
            else
                d += 2;
        }
        if (n == 1 && cnt != 0) {
            print_decompose(d, cnt);
        }
    }
}

void a() {
    int n;
    cout << "n = ";
    cin >> n;
    decompose(n);
}

void print_sequence(int v[101], int start, int end) {
    for (int i = start; i <= end; i++) {
        cout << v[i] << " ";
    }
}

void check_digit(int x, int a[10]) {
    if (x < 0)
        x = -x;
    while (x != 0) {
        a[x%10] = 1;
        x /= 10;
    }
}

void longest_sequence(int n, int v[101]) {
    int  len = 1, max_len = 0, start = 1, max_start, max_end;
    for (int i = 2; i <= n; i++) {
        bool ok = true;
        int a1[10] = {};
        int a2[10] = {};
        check_digit(v[i-1], a1);
        check_digit(v[i], a2);
        for (int j = 0; j < 10; j++) {
            if (a1[j] != a2[j]) {
                ok = false;
            }
        }
        if (ok) {
            len++;
            if (len>max_len) {
                max_len = len;
                max_start = start;
                max_end = i;
            }
        }
        else {
            start = i;
            len = 1;
        }
    }
    print_sequence(v, max_start, max_end);
}

void b() {
    int n, v[101];
    cout << "n = ";
    cin >> n;
    cout << "Enter numbers ";
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    longest_sequence(n, v);
}

int main() {
    a();
    b();
    return 0;
}