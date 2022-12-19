# 相同数字异或为0，任何数字与0异或为本身
```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        int size = nums.size();
        for(int i = 0;i < size;i++)
            sum ^= nums[i];
        return sum;
    }
};
```
