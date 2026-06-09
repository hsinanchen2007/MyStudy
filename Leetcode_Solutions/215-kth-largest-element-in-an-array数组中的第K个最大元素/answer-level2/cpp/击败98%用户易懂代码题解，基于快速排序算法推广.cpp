
```c++
class Solution {
public:
 int binaryFindKthLargest(vector<int>& nums,int begin,int end, int k)
{
	int mid_index = (begin+end) / 2;
	// 借鉴快速排序的二分思想找第k个最大的数
	int pivot=nums[mid_index];
	int left = begin, right = end;
	while (left<right)
	{

		 while (nums[left] < pivot)
			left++;
		while (nums[right] > pivot)
			right--;

		// 一般情况是left==right但是当left==right==pivot时候这个循环末尾的那两个语句会让left>right
		if (left >= right)
			break;
		// 此时nums[left]>=pivot, nums[right]<=pivot
		swap(nums[left], nums[right]);
		// 下面这个是用于跳出left==pivot==right这个情况的阻塞
		if (nums[left] == pivot && nums[right] == pivot)
		{
			left++;
		}
	}
	int pivot_index = (nums[right] == pivot) ? right : left;
	int pivot_seq_num = end-pivot_index+1;// >=轴心元素的个数
	if (pivot_seq_num == k)
		return pivot;
	if (pivot_seq_num < k)// 如果轴心元素是比第k大更大的数那就得从左侧找
		return binaryFindKthLargest(nums, begin, pivot_index -1, k - pivot_seq_num);
	else
	{
			return binaryFindKthLargest(nums, pivot_index+1, end, k);
	}

}
int findKthLargest(vector<int>& nums, int k) {
	return binaryFindKthLargest(nums,0,nums.size()-1, k);
}
};
```
