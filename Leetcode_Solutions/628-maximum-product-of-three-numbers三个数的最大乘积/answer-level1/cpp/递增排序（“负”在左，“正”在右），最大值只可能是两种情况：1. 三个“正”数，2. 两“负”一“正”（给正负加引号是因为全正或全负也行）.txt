```
class Solution {
public:

    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());    // 从小到大排序
        int len = nums.size();
        int max1 = nums[0] * nums[1] * nums[len-1];    // 两“负”一“正”
        int max2 = nums[len-3] * nums[len-2] * nums[len-1];    // 三个“正”数
        return max1 > max2 ? max1 : max2;    // 返回较大值
    }
};
```