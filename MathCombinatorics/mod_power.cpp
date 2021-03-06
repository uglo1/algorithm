//
// 累乗 a^n mod. m   O(log n)
//


#include <iostream>
using namespace std;


long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


int main() {
    cout << modpow(3, 45, 1000000007) << endl;
}