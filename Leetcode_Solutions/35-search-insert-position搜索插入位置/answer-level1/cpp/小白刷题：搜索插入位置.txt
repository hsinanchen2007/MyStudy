顺序查找，时间复杂度O(n)；二分查找，时间复杂度O(logn)

采用二分查找，注意边界问题

代码：
```
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int len = nums.size();
		if (len) {
			int start = 0, finish = len - 1;
			if (nums[start] >= target)
				return 0;
			else if (nums[finish] == target)
				return finish;
			else if (nums[finish] < target)
				return len;
			while (start < finish - 1) {
				int middle = (start + finish) >> 1;
				if (target == nums[middle])
					return middle;
				else if (target > nums[middle])
					start = middle;
				else
					finish = middle;
			}
			return finish;
		}
		return 0;
	}
};
```
