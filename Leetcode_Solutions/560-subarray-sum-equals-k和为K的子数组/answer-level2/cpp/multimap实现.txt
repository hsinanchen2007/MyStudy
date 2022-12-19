暴力法的思路是先计算累加和（从nums[0]到nums[i]的和），保存在nums[i]上
multimap直接保存了这个结果，供后面的元素查询
```
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //从暴力优化，用Multimap保存从第一个元素到该个元素的和，以及该元素的位置
        //那么后面的元素只要寻找前面存在的和为num[i]-k的位置的个数即可
		int len = nums.size(), res = nums[0] == k ? 1 : 0;
		unordered_multimap<int, int> sumAndIdx{ {nums[0],0},{0,-1} };
		for (int i = 1;i < len;++i) {
			nums[i] += nums[i - 1];
			res += sumAndIdx.count(nums[i]-k);
			sumAndIdx.emplace(nums[i], i);
		}
		return res;

        //暴力，a[j]-a[i]表示(i,j]区间上的和
        // int len=nums.size(),res=nums[0]==k?1:0;
        // for(int i=1;i<len;++i){
        //     nums[i]+=nums[i-1];
        //     if(nums[i]==k)++res;
        // }
        // for(int i=len-2;i>=0;--i){
        //     for(int j=len-1;j>i;--j)
        //         if(nums[j]-nums[i]==k)++res;
        // }
        // return res;
    }
};
```
