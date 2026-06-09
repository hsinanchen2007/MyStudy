想到两种方案：
方案1，实现hash，然后添加比较。c里面没有内置hash，需要手动实现，整型hash需要考虑负数问题。
方案2，先将数组排序，排序后去重，然后比较两个顺序数组，取出相同元素即可。
```


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//方法1：新建一个hash表，桶中元素为链表，正负存储在一个节点内
//方法2：先将俩数组排序去重，然后合并到一个数组，剔除单一的数
#define MAX(a,b) ((a) > (b) ? (a):(b))

void swap(int *a, int *b)
{
    if (a == b)
        return;
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
    return;
}

void quickSort(int *arr, int low, int high)
{
	int pivotKey, pivotLoc;
	int left = low;
	int right = high;
	if (low < high)
	{
		//保存枢轴点和枢轴值
		pivotLoc = (low + high) / 2;
		pivotKey = arr[pivotLoc];
		while (low < high)
		{
			while (low < pivotLoc && arr[low] <= pivotKey)low++;
			if (low < pivotLoc)
			{
				swap(arr+low, arr+pivotLoc);
				pivotLoc = low;
			}
			
			while(high > pivotLoc && arr[high] >= pivotKey)high--;
			if (high > pivotLoc)
			{
				swap(arr+high, arr+pivotLoc);
				pivotLoc = high;					
			}
		}
 
		quickSort (arr, left, pivotLoc);
		quickSort (arr, pivotLoc + 1, right);
	}
	return;
}

//去重
void deduplicate(int *nums, int *numsSize)
{
    int i, j, len = *numsSize;
    for (i = 0, j = 1; j < len; j++)
    {
        if (nums[j] == nums[i])
            *numsSize = *numsSize - 1;
        else
        {
            swap(nums+i+1, nums+j);
            i++;
        }        
    }
    return;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    
    int i,j,k,len, *ret;
    len = MAX(nums1Size, nums2Size);
    if (len <= 0) len = 1;
    
    ret = (int *)calloc(len, sizeof(int));
    *returnSize = 0;
    
    //特殊情况处理
    if (!nums1|| nums1Size < 0 || !nums2 || nums2Size < 0)
        return ret;
    
    //排序
    quickSort(nums1,0,nums1Size-1);
    quickSort(nums2,0,nums2Size-1);
    printf("A size:%d, B size:%d\n", nums1Size, nums2Size);
    //去重
    deduplicate(nums1, &nums1Size);
    deduplicate(nums2, &nums2Size);
    printf("A size:%d, B size:%d\n", nums1Size, nums2Size);
    
    //合并
    for (i = 0, j = 0, k = 0; i < nums1Size && j < nums2Size;)
    {
        if (nums1[i] == nums2[j])
        {
            ret[k] = nums1[i];
            i++;j++;k++;
        }
        else if (nums1[i] < nums2[j])
            i++;
        else
            j++;
    }
    
    *returnSize = k;
    return ret;
}


```
