### 解题思路
当数组只有一个元素时，在`nums[-1] = nums[n] = -inf`的条件下，答案为`0`。
先判断边界情况，即第一个元素和最后一个元素是否满足，若满足即返回其索引即可。
其他情况使用二分查找进行寻找。

### 代码

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 2] < nums[n - 1]) return n - 1;
        int ans = -1;
        search(nums, 0, n - 1, ans);
        return ans;
    }
    
    bool search(vector<int>& nums, int lo, int hi, int& ans) {
        if (lo + 1 == hi) return false;
        int m = lo + (hi - lo) / 2;
        if (nums[m - 1] < nums[m] && nums[m] > nums[m + 1]) {
            ans = m;
            return true;
        }
        return search(nums, lo, m, ans) || search(nums, m, hi, ans);
    }
};
```