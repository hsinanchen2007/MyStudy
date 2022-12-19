```
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()<=0)return 0;
        int count=1,max_length=1;
        for(int i=1;i<nums.size();++i){
        	if(nums[i]>nums[i-1])++count;
        	else count=1;
        	max_length=max(max_length,count);
		}
		return max_length;
    }
};
```
