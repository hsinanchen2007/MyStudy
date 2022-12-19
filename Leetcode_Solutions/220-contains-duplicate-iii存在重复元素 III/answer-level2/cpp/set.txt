### 解题思路
1. set.lower_bound确定下界
2. 找到的iterator合法则继续判断上界
3. 寻找的范围永远限定在步长边界内，越界的元素不需要insert

执行用时 :36 ms, 在所有 C++ 提交中击败了11.72% 的用户
内存消耗 :11.1 MB, 在所有 C++ 提交中击败了5.47%的用户

### 代码

```cpp
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
		const int val_diff_bound = t;
		set<long> ordered_nums;
		for(size_t i=0;i<nums.size();++i){
			auto ind = ordered_nums.lower_bound((long)((long)nums[i] - (long)val_diff_bound));
			if((ind != ordered_nums.end()) && (*ind <= (long)((long)nums[i] + (long)val_diff_bound))) return true;
			ordered_nums.insert(nums[i]);
			if(ordered_nums.size() > static_cast<size_t>(k)){
				ordered_nums.erase(nums[i-k]);
			}
		}
		return false;
	}
};
```