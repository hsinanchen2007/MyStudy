组合数公式:c(i,n) = (n!) / i! * (n - i)!
每一行都是二项展开的系数
计算:  c(i,n) / c(i - 1, n) = (n - i + 1) / i
所以第i项是第i-1项的(n - i + 1) / i倍

需要注意一下溢出的问题，cur定义为long
并且注意不能写成 cur = cur * ((n - i + 1) / i) ,
因为((n - i + 1) / i)会导致整数截断
```
class Solution {
 public:
  std::vector<int> getRow(int rowIndex) {
    int n = rowIndex;
    std::vector<int> res;
    res.resize(n + 1);
    long cur = res[0] = 1;
    for (int i = 1; i <= n / 2; ++i) {
      cur = cur * (n - i + 1) / i;
      res[i] = cur;
    }

    for (int i = 0, j = res.size() - 1; i < j; ++i, --j) {
      res[j] = res[i];
    }

    return res;
  }
};
```
