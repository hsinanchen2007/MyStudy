```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=0){
                swap(nums[i],nums[k]);
                k++;
            }
    }
};
```
第一次一分钟内一次ac，太激动了，发个题解