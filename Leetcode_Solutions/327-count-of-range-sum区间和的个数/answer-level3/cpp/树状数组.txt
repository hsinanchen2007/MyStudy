### 解题思路
分析该题，很明显的发现应该使用前缀和来保存，然后利用S[i] - S[j]来求取区间和；
那么到底哪些满足要求呢？在遍历的时候就需要查找S[0] ~ S[i - 1]之中哪些满足S[i] - upper <= S[k] <= S[i] - S[lower],如果满足，就可以将对应的计数加1,最后将count求出来即可。

随后想到如果S[i]能够排序就可以使用二分查找进行，就可以将复杂度缩减为O(n*lognN)。即是说，SUM[i]查找前面有多少个sum[j]在给定范围内，这就是前面有一个题了。使用树状数组进行排序，然后边左移边插入，就可以动态的获取左边或者是右边的值。

需要注意：应该在sum[i]里面添加一个0，代表sum[i]也可以进行筛选；
		上限、下限 的求取很关键，下限应该不包含target，上限应该包含target，然后需要注意找不到的情况下处理方式。lower_bound和upper_bound真的很傻比。其次unique加sort去重也是注意点；
		树状数组就不用多说了，和前面一样。
		注意数组是int，求和一定需要上升成long long。

### 代码

```cpp
class Solution {
public:
	int GetDownIndex(vector<long long>& S, long long target)
	{
		auto iter = lower_bound(S.begin(), S.end(), target);
		if (iter != S.end() && iter != S.begin()) {
			return(iter - S.begin());
		}
		return (target > S.back()) ? S.size() : 0;
	}
	int GetUpIndex(vector<long long>& S, long long target)
	{
		auto iter = upper_bound(S.begin(), S.end(), target);
		if (iter != S.end()) {
			return (iter - S.begin());
		}
		return (target >= S.back()) ? S.size() : 0;
	}
	int GetCurrentIndex(vector<long long>& S, int target)
	{
		auto iterPair = equal_range(S.begin(), S.end(), target);
		return (iterPair.first - S.begin() + 1);
	}
	int LowBit(int x) 
	{
		return x&(-x);
	}
	void Add(vector<long long>& treeArr, int x, int val) 
	{
		while(x < treeArr.size()) {
			treeArr[x] += val;
			x += LowBit(x);
		}
	}
	int Query(vector<long long>& treeArr, int x)
	{
		int ans = 0;
		while(x > 0) {
			ans += treeArr[x];
			x -= LowBit(x);
		}
		return ans;
	}
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) {
			return 0;
		}
		vector<long long> sum(nums.size(), 0);
		sum[0] = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			sum[i] =  sum[i - 1] + nums[i];
		}
		vector<long long> sortedNum(sum);
		sortedNum.push_back(0);
		sort(sortedNum.begin(), sortedNum.end());
		sortedNum.erase(unique(sortedNum.begin(), sortedNum.end()), sortedNum.end());

		vector<long long> treeArr(sortedNum.size() + 1, 0);
		Add(treeArr, GetCurrentIndex(sortedNum, 0), 1);
		int ans = 0;
		for (int i = 0; i < sum.size(); i++) {
			int upIndex = GetUpIndex(sortedNum, (sum[i] -lower));
			int downIndex = GetDownIndex(sortedNum, (sum[i] - upper));
			ans += (Query(treeArr, upIndex) - Query(treeArr, downIndex));
			Add(treeArr, GetCurrentIndex(sortedNum, sum[i]), 1);
		}
        return ans;
    }
};
```