```
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        //递增排序
        std::sort(nums.begin(),nums.end());
        //将奇数位元素求和
        int sum = 0;
        for(int k=0;k<nums.size();k+=2)
            sum += nums[k];
        return sum;
    }
};
```