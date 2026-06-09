```
class Solution {
public:
int missingNumber(vector<int>& nums) {
    if(nums[0]!=0)return 0;
    if(nums.size()==1&&nums[0]==0)return 1;
    if(nums.size()==1&&nums[0]==1)return 0;
	int n=nums[nums.size()-1];
    int sum=accumulate(nums.begin(),nums.end(),0);
	int expectedsum=n*(n+1)/2;
	if(expectedsum-sum!=0)return expectedsum-sum;
    else return nums[nums.size()-1]+1;
}
};
```
