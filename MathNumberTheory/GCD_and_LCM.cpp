//
// GCD (最大公約数) , LCM (最小公倍数)
//

/*
  a と b の最大公約数を G、最小公倍数を L とすると
     GL = ab
  が成り立つ。よって、 
     L = a/g * b (a は g で割り切れる)
   注意点として、L = a*b/g としてしまうと a*b の計算する部分でオーバーフローの危険がある。
*/

#include <iostream>
using namespace std;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

long long LCM(long long a, long long b) {
    long long g = GCD(a, b);
    return a / g * b;
}


int main() {
    int N; cin >> N;
    long long res = 1;
    // N個の数の最小公倍数
    for (int i = 0; i < N; ++i) {
        long long a; cin >> a;
        res = LCM(res, a);
    }
    cout << res << endl;
}