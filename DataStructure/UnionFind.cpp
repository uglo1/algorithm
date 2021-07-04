/*
    ei1333さんのやつ
    集合を高速に扱うためのデータ構造. 集合を合併する操作(unite),
   ある要素がどの集合に属しているか(find) を問い合わせる操作を行うことが出来る.
    unite(x, y): 集合 x と y を併合する. 併合済のとき false, 未併合のとき true
   が返される. find(k): 要素 k が属する集合を求める. size(k): 要素 k
   が属する集合の要素の数を求める. same(x, y): 要素 x, y
   が同じ集合に属するか判定する.
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

struct UnionFind {
  vector<int> data;

  UnionFind() = default;

  explicit UnionFind(size_t sz) : data(sz, -1) {}

  void init(int sz) { data.resize(sz, -1); }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  int find(int k) {
    if (data[k] < 0) return (k);
    return data[k] = find(data[k]);
  }

  int size(int k) { return -data[find(k)]; }

  bool same(int x, int y) { return find(x) == find(y); }
};

int main() {
  int n;
  cin >> n;
  UnionFind uf(n);
  uf.unite(2, 3);
}