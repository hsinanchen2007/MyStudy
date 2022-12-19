```
class Solution {
public:
	int findMagicIndex(vector<int>& nums) {
		if (nums.empty() || nums.back() < 0 || nums[0] > int(nums.size() - 1))
			return -1;
		return find(nums, 0, int(nums.size() - 1));
	}
	int find(vector<int>& nums, int s, int e)
	{
		if (s > e)
			return -1;
		int ret = INT_MAX;
		int mid = s + (e - s) / 2;
		if (nums[mid] == mid && ret > mid)
			ret = mid;
		int retl = -1;
		//if (s <= mid - 1)
		retl = find(nums, s, mid - 1);
		if (retl != -1 && ret > retl)
			ret = retl;
		int retr = -1;
		if (ret == INT_MAX)// && mid + 1 <= e)
			retr = find(nums, mid + 1, e);
		if (retr != -1 && ret > retr)
			ret = retr;
		return ret == INT_MAX ? -1 : ret;
	}
};
```
