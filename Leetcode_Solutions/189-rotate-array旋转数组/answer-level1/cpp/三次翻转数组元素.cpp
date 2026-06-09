1. 翻转0-len:    nums={**7,6,5,4,3,2,1**}
2. 翻转0-k%len-1:  nums={**5,6,7**,4,3,2,1}
3. 翻转k%len-len:nums={5,6,7,**1,2,3,4**}
``` C++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty()) return;
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k%nums.size()-1);
        reverse(nums,k%nums.size(),nums.size()-1);
    }
    
    void reverse(vector<int> &nums,int start,int end)
    {
        while(start<end)
        {
            int temp=nums[start];
            nums[start++]=nums[end];
            nums[end--]=temp;
        }
    }
};
```