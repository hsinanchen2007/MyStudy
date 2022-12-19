```
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int countmax=0;
        if(nums.size()==0)
            return 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
                count++;
            else
                count=0;
            if(count>countmax)
                countmax=count;
        }
        return countmax;
        
    }
};
```