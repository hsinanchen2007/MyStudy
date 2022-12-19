简单遍历即可
```
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        const int S = nums.size();
        const int half = S / 2;
        int count = 0;
        for (int i = 0; i < S && count <= half; count += (nums[i++] == target));
        return count > half;
    }
};
```
