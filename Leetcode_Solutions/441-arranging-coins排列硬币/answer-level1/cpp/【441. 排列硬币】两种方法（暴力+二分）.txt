
### 思路一：暴力
逐行减

### 代码
时间复杂度：O(n)
```c++
class Solution {
public:
    int arrangeCoins(int n) {
        int cur = 1, rem = n - 1;
        while (rem >= cur + 1) {
            ++cur;
            rem -= cur;
        }
        return n == 0 ? 0 : cur;
    }
};
```

### 思路二：二分
**注意**：中间乘积超出整数范围

### 代码
时间复杂度：O(logn)
```cpp
class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 1) return n;
        int left = 1, right = n;
        while (left <= right) {
            long int k = left + (right - left) / 2;
            long int t = (k + 1) * k / 2;//乘积超出整数范围
            if (t == n) return k;
            else if (t < n) left = k + 1;
            else right = k - 1;
        }
        return right; 
    }
};
```


