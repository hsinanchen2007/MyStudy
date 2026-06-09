### 解题思路
答案只可能是最大三个数的乘积或最大数和最小两个数的乘积（此时两个最小数均为负数）。

### 线性扫描，O(n)时间复杂度，O(1)空间复杂度

```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int f_max, s_max, t_max;
        f_max = s_max = t_max = INT32_MIN;
        int f_min, s_min;
        f_min = s_min = INT32_MAX;
        int s = nums.size();
        for (int num : nums) {
            if (num > f_max) {
                t_max = s_max;
                s_max = f_max;
                f_max = num;
            } else if (num > s_max) {
                t_max = s_max;
                s_max = num;
            } else if (num > t_max) {
                t_max = num;
            }

            if (num < f_min) {
                s_min = f_min;
                f_min = num;
            } else if (num < s_min) {
                s_min = num;
            }
        }
        return max(f_max * s_max * t_max,
                    f_max * f_min * s_min);
    }
};
```
### 排序，O(nlogn)时间复杂度，O(1)空间复杂度
```
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
            int s = nums.size();
            sort(nums.begin(), nums.end());
            return max(nums[0] * nums[1] * nums[s - 1],
                       nums[s - 1] * nums[s - 2] * nums[s - 3]);
    }
```
![2020-02-13_18-07.png](https://pic.leetcode-cn.com/2c67f6504197798a8ad08b1b3baa5e916bec55e7d49535cedef0c72f514d0717-2020-02-13_18-07.png)
