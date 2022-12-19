
```
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
    	int i,max=0;
        for(i=1;i<nums.size();i++)//找出最大值下标
        	if(nums[i]>nums[max])
        		max=i;
        for(i=0;i<nums.size();i++){//判断最大值是否至少为其他数的两倍
        	if(i!=max){
        		if(nums[max]<nums[i]*2)
        			return -1;
			}
		}
		return max;
    }
};
```
