#### 解题思路：
`nums[]` 为严格递增序列，`left` 为二分下界，`right` 为二分上界，`target` 为欲查询数。

二分查找是基于有序序列的查找方法，该算法一开始令 `[left, right]` 为整个序列的下标区间，然后每次测试当前 `[left, right]` 的中间位置 `mid = (left + right) / 2`，判断 `nums[mid]` 与欲查询的 `target` 的大小：
第一类：需查找和目标值完全相等的数
假设序列严格单调递增
1.如果 `nums[mid] == target`，说明查找成功，退出查询
2.如果 `nums[mid] > target`，说明目标值元素 `target` 在 `mid` 位置的左边，因此往左子区间 `[left, mid - 1]` 继续查找
3.如果 `nums[mid] < target`，说明目标值元素 `target` 在 `mid` 位置的右边，因此往右子区间 `[mid + 1, right]` 继续查找

因此其时间复杂度是 $O(logn)$。
#### 代码：
```c++ [-C++]
//right = nums.size() - 1 ;写法一
int binarySearch(int nums[], int left, int right, int target) {
	int mid;        
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] > target) right = mid - 1;        // 往左区间查询
		else left = mid + 1;                                 // 往右区间查询
	}
	return -1;                    // 未查询到
}
```
````c++ 
//right = nums.size() ;写法二
int binarySearch(int nums[], int left, int right, int target) {
	int mid;        
	while (left < right) {
		mid = left + (right - left) / 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] > target) right = mid;        // 往左区间查询
		else left = mid + 1;                                 // 往右区间查询
	}
	return -1;                    // 未查询到
}
```

如果序列是递减的，将 nums[mid] > target  改为 nums[mid] < target  即可。

注意：如果二分上界超过 int 型数据范围的一半，那么语句  mid = (left + right) / 2有可能导致溢出，应改为  mid = left + (right - left) / 2 。

接下来讨论更进一步的问题：如果递增序列 nums 中的元素可能重复，那么如何对给定的 target ，
求出序列中第一个大于等于 target 的元素的位置 L 以及第一个大于 target 的元素的位置 R ，这样元素 target 在序列中的存在区间就是[L, R) 。

第二类：查找第一个大于等于target的元素（本题的内容）（lower_bound）

1.如果 nums[mid] ≥ target ，说明第一个大于等于 target 的元素的位置一定在 mid 处或 mid 的左侧，应往左子区间[left, mid] 继续查询，即令 right = mid 。
2.如果 nums[mid] < target ，说明第一个大于等于 target 的元素的位置一定在 mid 的右侧，应往右子区间[mid + 1, right] 继续查询，即令 left = mid + 1 。

```
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size();
		int mid;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (nums[mid] >= target) right = mid;
			else left = mid + 1;
		}
		return left;
	}
};
```
考虑到欲查询元素有可能比序列中的所有元素都要大，此时应当返回 nums.size() ，因此二分上界是 nums.size() ，故二分的初始区间为[left, right] = [0, nums.size()] 。

第三类：查找第一个大于target的元素(upper_bound)

1.如果 nums[mid] > target ，说明第一个大于 target 的元素的位置一定在 mid 处或 mid 的左侧，应往左子区间[left, mid] 继续查询，即令 right = mid 。
2.如果 nums[mid] ≤ target ，说明第一个大于 target 的元素的位置一定在 mid 的右侧，应往右子区间[mid + 1, right] 继续查询，即令 left = mid + 1 。

```
int upper_bound(int nums[], int left, int right, int target) {
	int mid;        
	while (left < right) {
		mid = left + (right - left) / 2;
		if (nums[mid] > target) right = mid;    
		else left = mid + 1;    
	}
	return left;
}

```
lower_bound 函数和 upper_bound 函数的代码高度相似，其实这两个函数都在解决这样一个问题：
寻找有序序列中第一个满足某条件的元素的位置。此处总结了解决此类问题的固定模版：

解决“寻找有序序列第一个满足某条件的元素的位置”问题的固定模版
二分区间为左闭右闭的 [left,right]，初值必须能覆盖解的所有可能取值。
```
int conditionSearch(int nums[], int left, int right, int target) {
	int mid;        
	while (left < right) {
		mid = left + (right - left) / 2;
		if (condition) {        // 条件成立，第一个满足条件的元素位置 <= mid
			right = mid;        // 左区间
		}
		else {                  // 条件不成立，第一个满足条件的元素位置 > mid
			left = mid + 1;     // 右区间
		}
	}

	return left;          // 返回夹出来的位置
}
```
此外，如果想要寻找最有一个满足 “条件 C”的元素的位置，则可以先求第一个满足 “条件 !C”的元素的位置，然后将该位置减 1 即可。

