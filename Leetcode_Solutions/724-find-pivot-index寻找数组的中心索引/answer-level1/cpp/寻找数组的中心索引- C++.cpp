```
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // 第一次遍历，求数组中所有元素之和
        int sum = 0;
        for (int item : nums)
            sum += item;
        cout << "sum = " << sum << endl;
        
        // 第二次遍历，比较当前元素左侧和右侧数字之和（总和-左侧-当前）是否相等
        int sum_left = 0;
        for (int i=0; i<nums.size(); i++) {
            if (sum_left == sum - sum_left - nums[i])
                return i;
            sum_left += nums[i];
        }
        
        return -1;
    }
};

```
