```
class Solution{
	public:
	    int pivotIndex(vector<int>& nums) {
	    	int sum=0,tmp=0;
        	for(int i=0;i<nums.size();++i)sum+=nums[i];
        	for(int i=0;i<nums.size();++i){
        		if(sum-nums[i]==2*tmp)return i;
        		tmp+=nums[i];
			}
			return -1;
    	} 
};
```
