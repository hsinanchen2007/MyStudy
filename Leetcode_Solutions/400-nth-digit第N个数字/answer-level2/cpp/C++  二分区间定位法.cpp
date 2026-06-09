lower_bound就是利用的二分法来定位的，这里利用c++自带的lower_bound来实现区间定位

```C++ []
class Solution {
public:
    const int N = 1e8;
    vector<long> s;
    Solution() {
        s.push_back(0L);
        for (int i = 1, n = 10; n <= N; ++i, n *= 10) {
            s.push_back(s.back() + (long)i * (long)(n - n / 10));
        }
    }
    int findNthDigit(int n) {
        int k = lower_bound(s.begin(), s.end(), n) - s.begin();
        int u = pow(10, k - 1) + (n - s[k - 1] - 1) / k;
        int v = (n - s[k - 1] - 1) % k;
        return (u / (int)pow(10, k - 1 - v)) % 10;
    }
};
```

![image.png](https://pic.leetcode-cn.com/ba9ef65023b9b475c5fadf39a64a566125dd9fc582447bbeab37f7a27aea5b22-image.png)
