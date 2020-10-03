#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
using std::pair;

pair<int,int> partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int j1 = l;
  int j2 = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      j2++;
      swap(a[i], a[j2]);
    }
  }
  j1=j2;
  for(int i=l+1; i< j2; i++)
  {
    if(a[i] == x) {
      j1--;
      swap(a[i], a[j1]);
    }
  }

  swap(a[l], a[j2]);
  return std::make_pair(j1,j2);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  pair<int,int> m = partition3(a, l, r);

  randomized_quick_sort(a, l, m.first - 1);
  randomized_quick_sort(a, m.second + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
