出数据的人全家福贵嗷
```c++
class Solution {
public:
  double myPow(double x, int n) {
    long long m = n;
    if (n < 0) {
      x = 1 / x;
      m = -m;
    }
    double ret = 1.;
    for (; m; m >>= 1, x *= x) {
      if (m & 1) ret *= x;
    }
    return ret;
  }
};
```