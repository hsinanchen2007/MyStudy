解题思路:在暴力的基础上做了一点点改进，记录下每个窗口的最大值，记录的时候注意是大于等于而不是大于，因为下标小的最大值在窗口向右移动时更容易丢失。如果在窗口移动的时候没有丢失最大值，新增的值与最大值比较即可，如果最大值在窗口移动时丢失，就暴力搜索最大值。
```
class Solution {
public:
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n=nums.size(),max=-65530,maxindex=0;
	vector<int> ans;
    if(n==0)return ans;
	for(int j=0;j<k;j++){
		if(nums[j]>=max){
			max=nums[j];
			maxindex=j;
		}
	}
	ans.push_back(max);
	for(int i=1;i+k-1<n;i++){
		if(maxindex==i-1){
			max=-65530;
			for(int j=i;j<k+i;j++){
				if(nums[j]>=max){
					max=nums[j];
					maxindex=j;
				}
			}
			ans.push_back(max);
		}else{
			if(nums[i+k-1]>=max){
				ans.push_back(nums[i+k-1]);
				max=nums[i+k-1];
				maxindex=i+k-1;
			}else{
				ans.push_back(max);
			}
		}
	}
	return ans;
}
};
```
