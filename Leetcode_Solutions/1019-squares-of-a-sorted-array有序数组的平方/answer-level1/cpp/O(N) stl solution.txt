```c++
class Solution {
 public:
  std::vector<int> sortedSquares(std::vector<int>& A) {
    std::vector<int> ans(A.size());
    std::vector<int>::iterator it1 = std::lower_bound(A.begin(), A.end(), 0);
    std::vector<int>::reverse_iterator it2(it1);
    std::for_each(A.begin(), A.end(), [](int& i) { i *= i; });
    std::merge(it1, A.end(), it2, A.rend(), ans.begin());
    return ans;
  }
};
```
注意由正向迭代器构造反向迭代器时，指向前一个元素