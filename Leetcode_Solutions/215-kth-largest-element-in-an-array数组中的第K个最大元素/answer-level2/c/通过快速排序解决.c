
//Partition是快速排序的核心函数，它返回某一个数在一个数组中的最终排序位置
int Partition(int *A, int low, int high)
{
	int pivot = A[low];
	while (low < high)
	{
		while (low < high && A[high] >= pivot) --high;
		A[low] = A[high];
		while (low < high && A[low] <= pivot) ++low;
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}

//如果Partition返回的不是最终位置，则进行判断，如果返回元素位置高于需求位置，那么
//就在之前的元素中进行寻找；如果返回的位置低于需求位置，则在返回位置之后的元素中寻找。
//numsSize-k是因为题目中给的k是第k大的元素，而Partition返回的是从低到高的第n个元素
int findKthLargest(int* nums, int numsSize, int k) 
{
	int low = 0, high = numsSize - 1;
	int pos = Partition(nums, low, high);
	if (pos == numsSize - k)
	{
		return nums[pos];
	}
	else
	{
		while (pos != numsSize - k)
		{
			if (pos > numsSize - k)
			{
				pos = Partition(nums, low, pos - 1);
			}
			else
			{
				pos = Partition(nums, pos+1,high);
			}
		}
		return nums[pos];
	}

}