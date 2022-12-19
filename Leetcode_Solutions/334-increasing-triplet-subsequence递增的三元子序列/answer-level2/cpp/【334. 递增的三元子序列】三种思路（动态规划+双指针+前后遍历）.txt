### 思路一：动态规划
每次寻找比当前数小的元素个数。

### 代码
时间复杂度：O(n^2)
空间复杂度：O(n)
```cpp
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, 1);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                if (dp[i] >= 3) return true;
            }
        }
        return false;
    }
};
```

### 思路二：双指针
m1, m2保存两个较小数，找出一个同时大于m1和m2的数即返回。

### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX, m2 = INT_MAX;
        for (auto a : nums) {
            if (m1 >= a) m1 = a;
            else if (m2 >= a) m2 = a;
            else return true;
        }
        return false;
    }
};
```

### 思路三：前后遍历
定义两个数组forward[i]和backward[i]，forward[i]从前向后遍历，保存[0, i]之间最小元素值，backward[i]从后向前遍历，保存[i, size - 1]间最大元素值。然后从前向后遍历，如果找到一个数满足forward[i] < nums[i] < backward[i]，则表示三元子序列存在。
比如：
nums[i]:   8 3 5 1 6
forwa[i]:  8 3 3 1 1 
backw[i]:8 6 6 6 6

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int size = nums.size();
        vector<int> f(size, nums[0]), b(size, nums.back());
        for (int i = 1; i < size; ++i) {
            f[i] = min(f[i - 1], nums[i]);
        }
        for (int i = size - 2; i >= 0; --i) {
            b[i] = max(b[i + 1], nums[i]);
        }
        for (int i = 0; i < size; ++i) {
            if (f[i] < nums[i] && nums[i] < b[i]) return true;
        }
        return false;
    }
};
```

