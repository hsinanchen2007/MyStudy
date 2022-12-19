用异或和线性滚动，利用了原vector的空间，居然消耗了11.4MB的内存，决定试一试C语言
```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i=1;i<nums.size();i++)
            nums[i]^=nums[i-1];
        return nums[nums.size()-1];
    }
};
```
