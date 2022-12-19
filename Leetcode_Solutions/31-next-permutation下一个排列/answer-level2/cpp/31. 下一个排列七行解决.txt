a）从后向前查找第一个相邻元素对(i-1,i)，并且满足A[i-1] < A[i]。
易知，此时从i到end必然是降序。可以用反证法证明，请自行证明。

b）在[i,end)中寻找一个最小的j使其满足A[i-1]<A[j]。
由于[i,end)是降序的，所以必然存在一个j满足上面条件；并且可以从后向前查找第一个满足A[i-1]<A[j]关系的j，此时的j必是待找的j。

c）将i-1与j交换。
此时，i-1处变成比i-1大的最小元素，因为下一个全排列必须是与当前排列按照升序排序相邻的排列，故选择最小的元素替代i-1。
易知，交换后的[i,end)仍然满足降序排序。因为在(j,end)中必然小于i-1，在[i-1,j)中必然大于j，并且大于i-1。

d）逆置[i,end)
由于此时[i,end)是降序的，故将其逆置。最终获得下一全排序。

注意：如果在步骤a)找不到符合的相邻元素对，即此时i=begin，则说明当前[begin,end)为一个降序顺序，即无下一个全排列，STL的方法是将其逆置成升序。
```
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i=0, j=nums.size()-1;
		for(i=nums.size()-1; i && nums[i-1]>=nums[i]; --i);
		if(i){
			for(j=nums.size()-1; i<j && nums[i-1]>=nums[j]; --j);
			swap(nums[i-1],nums[j]);
		}
		reverse(nums.begin()+(i-1==j?0:i),nums.end());
	}
};
```