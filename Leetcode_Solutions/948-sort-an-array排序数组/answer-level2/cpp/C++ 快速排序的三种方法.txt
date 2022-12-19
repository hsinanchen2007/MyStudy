快速排序
### 分割操作，单向调整
```cpp
class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		QuickSort(nums, 0, nums.size()-1);
		return nums;
	}
	void QuickSort(vector<int>& nums,int l,int r) {
		if (l<r)
		{
			int mid = partition(nums, l, r);
			QuickSort(nums, l, mid-1);//注意点，l和r的值自己写错
			QuickSort(nums, mid + 1, r);//注意点,l和r的值自己写错
		}
	}
	int partition(vector<int>& nums, int l, int r)
	{
		//选取不同的主元，交换方式不一样，选取左主元，得从右向左遍历，且判断该pivot是否小于当前元素，小于则交换
		//下面以右主元为例
		int pivot = nums[r];
		//两个指针,一者移动
		int i = l, j = l,temp;
		//遍历序列，找主元应该插入的位置
		for (;j<r;j++)
		{
			//交换
			if (nums[j] < pivot) {
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
				i++;
			}
		}
		nums[r] = nums[i];
		nums[i] = pivot;
		return i;//返回分割位置
	}
};
```
### 分割操作，双向调整
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
### 分割操作，双向调整，加入随机函数
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
			int partition = randomPartition(nums, l, r);
			QuickSort(nums, l, partition - 1);
			QuickSort(nums, partition + 1, r);
		}
	}
	int randomPartition(vector<int>& nums, int l, int r)
	{
		int i = (rand() % (r - l + 1)) + l;//产生[a,b]的随机整数
		swap(nums[i], nums[l]);
		return partition(nums, l, r);
	}
	int partition(vector<int>& nums, int l, int r)
	{
		int pivot = nums[l];
		int i = l + 1, j = r;//双指针，分别指向首尾
		while (true)
		{
			while (i <= j && nums[i] <= pivot) i++;
			while (i <= j && nums[j] >= pivot) j--;
			if (i > j) break;
			//交换位置
			swap(nums[i], nums[j]);
		}
		//交换主元
		swap(nums[j], nums[l]);
		return j;
	}
};
```