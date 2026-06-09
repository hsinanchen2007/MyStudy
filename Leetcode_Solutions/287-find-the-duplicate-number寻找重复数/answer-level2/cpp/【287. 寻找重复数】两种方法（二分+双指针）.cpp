## 思路一：二分
整数范围[1, n], 二分取mid, 然后遍历数组，统计小于等于mid元素个数为cnt，如果cnt小于等于mid表示没有重复数字，则重复数字出现在[mid + 1, n]范围内，否则重复数字出现在[1, mid]范围内，再次二分知道范围区间为1，即找到重复数字。
### 代码
时间复杂度：O(nlogn)
```c++
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2, cnt = 0;            
            for (int n : nums) {
                if (n <= mid) {
                    ++cnt;
                }
            }
            if (cnt <= mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return right;
    }
};
```

## 思路二：双指针
很难想到。
### 代码
时间复杂度：O(n)
```c++
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[0], f = nums[0];
        do {
            s = nums[s];
            f = nums[nums[f]];
        } while (s != f);

        f = nums[0];
        while (s != f) {
            s = nums[s];
            f = nums[f];
        }
        return s;
    }
};
```

