### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		QuickSort(nums, 0, nums.size() - 1);
		return nums;
	}
	void QuickSort(vector<int>& nums, int l, int r) {
		if (l < r)
		{
			int mid = partition(nums, l, r);
			QuickSort(nums, l, mid - 1);//注意点，l和r的值自己写错
			QuickSort(nums, mid + 1, r);//注意点,l和r的值自己写错
		}
	}
	int partition(vector<int>& nums, int l, int r)
	{
		int pivot = nums[l];
		int i = l + 1, j = r;
		while (true)
		{
			while (i <= j && nums[i] <= pivot) i++;//寻找比pivot大的元素
			while (i <= j && nums[j] >= pivot) j--;//寻找比pivot小的元素
			if(i>j) break;
			swap(nums[i], nums[j]);
		}
		//把arr[j]和主元交换
		swap(nums[j], nums[l]);
		return j;//为什么返回j而不是i，因为swap是先执行i++的while语句，如果和下面的替换顺序，则返回i
	}
};

```