#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int T;
    cin >> T;
    for(int i=0;i<T;i++) {
        int n;
        cin >> n;
        int count = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                int x = i;
                int y = n / i;
                if (gcd(x, y) == 1)
                    count++;
                if (x != y && gcd(y, x) == 1)
                    count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
