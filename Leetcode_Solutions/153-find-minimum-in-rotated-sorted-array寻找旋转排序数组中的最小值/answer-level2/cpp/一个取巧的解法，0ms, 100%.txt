> 旋转后的数组是两段升序序列，最小值一定在旋转点和起始点中。
```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size(),mins=INT_MAX;
        
        mins=nums.front();
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1])
                mins=min(mins,nums[i]);
        }
        return mins;
    }
};
```