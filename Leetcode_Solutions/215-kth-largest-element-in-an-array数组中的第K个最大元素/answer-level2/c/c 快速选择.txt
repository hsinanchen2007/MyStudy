```
void swap(int*, int, int);
int qselect(int*, int, int, int);
int partition(int *, int, int, int);
int findKthLargest(int* nums, int numsSize, int k){
	
	return qselect(nums, 0, numsSize - 1, numsSize - k);
}

int qselect(int* nums, int left, int right, int k)
{
	if(left == right)
	{
		return nums[left];
	}
	
	int pivot_index = (right + left)/2; 
    // pivot的选择对性能影响非常大，对于测试用例 (right + left)/2 8ms， right 100ms
	
    pivot_index = partition(nums, left, right, pivot_index);
	
    if(pivot_index > k)
	{
		return qselect(nums, left, pivot_index - 1, k);
	}
	else if (pivot_index < k)
	{
		return qselect(nums, pivot_index + 1, right, k);
	}
	else
	{
		return nums[pivot_index];
	}
}

int partition(int * nums, int left, int right, int pivot_index)
{
	int store_index = left;
	swap(nums, pivot_index, right);
	for(int i = left; i < right; i++)
	{
		if(nums[i] < nums[right])
		{
			swap(nums,store_index,i);
			store_index++;
		}
	}
    swap(nums,store_index,right);
	return store_index;
}

void swap(int* nums, int i, int j)
{
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}
```
