```C++ []
class Solution {
public:
    int smallestFactorization(int a) {
        if (a == 1) return 1;
        vector<int> nums;
        for (int i = 9; i >= 2 && a > 1; --i) {
            while (a % i == 0) {
                nums.push_back(i);
                a /= i;
            }
        }
        if (a > 1 || nums.size() > 10) return 0;
        long res = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res = res * 10 + nums[i];
        }
        return res > INT_MAX ? 0 : res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/fe4c2b803a239a46ac25a40d45f2cc48313710d0141ac2b979bfac1485b61de4-image.png)
