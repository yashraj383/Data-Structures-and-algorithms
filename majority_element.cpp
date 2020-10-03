#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  sort(a.begin(), a.end());
  int count;

  for(int i = 0; i<a.size()-1; i++)
  {
    int count =1;
    while(a[i]==a[i+1])
    {
      count++;
      i++;
    }
    //std::cout << count <<"-ct-"<<a[i] <<'\n';
    if(count > (a.size())/2 ){
      std::cout << 1 <<'\n' ;
      return 0;
    }
  }
  std::cout << 0<<'\n';
  return 0 ;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  get_majority_element(a, 0, a.size()) ;
}
