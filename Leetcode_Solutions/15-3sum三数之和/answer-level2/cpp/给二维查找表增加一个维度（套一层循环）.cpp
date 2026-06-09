### 解题思路
求两个数字的和等于一个目标值，值A = 目标值 - 值B。
求三个数字的和等于一个目标值，for (遍历可能出现的值A) { 动态目标值即所给目标值-值A = 值B + 值C}
对数组排序，能起到剪枝和去重的效果。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        if (nums.empty()) return ans;
        sort(nums.begin(), nums.end());
        if (nums[0] > 0 || nums.back() < 0 || nums.size() < 3) return ans;
        for (int i = 0; i < nums.size(); ++i) { // i固定为最左边的元素 可以避免另外两个指针与i重合 nums[i]即值A
            if (i && nums[i] == nums[i-1]) continue; // 跳过重复字段
            int target = 0 - nums[i]; // 动态目标值
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int now = nums[left] + nums[right];
                if (now == target) {
                    vector<int> v;
                    v.emplace_back(nums[i]);
                    v.emplace_back(nums[left]);
                    v.emplace_back(nums[right]);
                    ans.emplace_back(v);
                    while (left < right && nums[left+1] == nums[left]) ++left; // 跳过重复字段
                    while (left < right && nums[right-1] == nums[right]) --right;
                    ++left; --right;
                }
                else if (now < target) ++left;
                else --right;
            }
        }
        return ans;
    }
};
```