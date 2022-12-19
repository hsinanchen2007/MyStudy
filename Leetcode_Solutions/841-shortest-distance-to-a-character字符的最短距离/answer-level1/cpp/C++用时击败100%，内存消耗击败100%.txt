### 解题思路
二分查找，如果目标值存在则返回0。
不存在 l = 大于目标值的最小值（如果存在）
	  r = 小于目标值的最大值（如果存在）
然后返回和目标值最近的值

### 代码

```cpp
class Solution {
public:
	int binarySearch(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (target == nums[mid]) return 0;
			else if (target > nums[mid]) l = mid + 1; 
			else r = mid - 1;
		}
		if (l < nums.size() && r >= 0) {
			return min(nums[l] - target, target - nums[r]);
		}
		else if (l < nums.size()) return nums[l] - target;
		return target - nums[r];
	}

    vector<int> shortestToChar(string S, char C) {
    	vector<int> nums;
    	int len = S.size();
    	for (int i = 0; i < len; ++i) {
    		if (S[i] == C) nums.push_back(i);
    	}

    	vector<int> ans(len, 0);
    	for (int i = 0; i < len; ++i) {
    		ans[i] = binarySearch(nums, i);
    	}
    	return ans;
    }
};
```