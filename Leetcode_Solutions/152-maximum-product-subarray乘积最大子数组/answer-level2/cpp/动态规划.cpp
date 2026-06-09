### 解题思路
存一个最小值和一个最大值用来更新。

### 代码

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        pair<int, int> temp(nums[0], nums[0]);
        int re = nums[0];
        for (int i=1; i<nums.size(); i++) {
            int maxVal = max(max(nums[i]*temp.first, nums[i]*temp.second), nums[i]);
            re = max(maxVal, re);
            int minVal = min(min(nums[i]*temp.first, nums[i]*temp.second), nums[i]);
            temp = make_pair(maxVal, minVal);
        }
        return re;
    }
};
```