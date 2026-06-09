循环本身就带有判断大小的功能，不需要用其他算法
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        while (i < nums.size() && nums[i] < target) {
            i++;
        }
        return i;
    }
};
```
