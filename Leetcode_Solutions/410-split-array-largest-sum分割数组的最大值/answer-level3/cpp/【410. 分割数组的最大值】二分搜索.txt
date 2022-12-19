## 思路一：二分
参考：[410. Split Array Largest Sum](https://github.com/grandyang/leetcode/issues/410)
对子数组最大和进行二分。
### 代码
```c++
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {        
        long int left = 0, right = 0;
        for (int i = 0; i < nums.size(); ++i) {
            left = max((int)left, nums[i]);
            right += nums[i];
        }
        while (left < right) {
            long mid = left + (right - left) / 2;
            if (can_split(nums, m, mid)) right = mid;
            else left = mid + 1;
        }
        return right;
    }

    bool can_split(vector<int> &nums, int m, long int sum) {
        long cnt = 1, curSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            curSum += nums[i];
            if (curSum > sum) {
                curSum = nums[i];
                ++cnt;
                if (cnt > m) return false;
            }
        }
        return true;
    }
};
```
