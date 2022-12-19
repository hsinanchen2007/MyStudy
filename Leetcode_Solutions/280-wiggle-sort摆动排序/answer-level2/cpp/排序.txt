### 解题思路
先排序，然后在两两交换数组值即可。 index + 2 与 index + 1交换。

### 代码

```cpp
class Solution {
public:
	void DFSRefreshNums(vector<int>& nums, int index)
	{
		int numMaxIndex = nums.size() - 2;
		if (numMaxIndex <= index) {
			return;
		}
		int nextNum = nums[index + 2];
		nums[index + 2] = nums[index + 1];
		nums[index + 1] = nextNum;
		DFSRefreshNums(nums, index + 2);
	}
    void wiggleSort(vector<int>& nums) {
		if (nums.empty() || nums.size() == 1) {
			return;
		}
		sort(nums.begin(), nums.end());
		DFSRefreshNums(nums, 0);
    }
};
```