```
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pre=0,sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
        }
        for(int i=0;i<nums.size();++i){
            if(pre*2+nums[i]==sum) return i;
            else pre+=nums[i];
        }
        return -1;        
    }
};
```
