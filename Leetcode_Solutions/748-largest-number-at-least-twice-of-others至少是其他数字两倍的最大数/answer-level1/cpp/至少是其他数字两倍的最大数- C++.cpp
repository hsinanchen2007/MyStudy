```
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        // 特殊情况处理
        if (nums.size() == 1)
            return 0;
        
        // 单次遍历，找寻数组中的最大数字和第二大数字
        int big_1_index = 0;
        int big_2 = INT_MIN;
        
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] > nums[big_1_index]) {
                big_2 = nums[big_1_index];
                big_1_index = i;
            } else if (nums[i] > big_2) {
                big_2 = nums[i];
            }
        }
        cout << nums[big_1_index] << " " << big_2 << endl;
        
        // 检查最大数字是否大于第二大数组的两倍
        if (nums[big_1_index] >= big_2 * 2)
            return big_1_index;
        else
            return -1;
    }
};
```
