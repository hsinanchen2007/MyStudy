### 解题思路
抄的前面大哥的，但有一些细节可以学习：
1. “*returnSize++”这种是错误的写法，需要(*returnSize)++ 这样才可以

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 /*快排主体*/
int sort(int* array, int low, int high){
	int pivot = array[low];
	while (low < high){
		while (low < high && array[high] >= pivot){//请注意这里的等号，异常重要。因为如果不是>=的话，加入样例为{5，5，5，5}，那么就是死循环了！ 
			high--;
		}
		array[low] = array[high];
		while (low < high && array[low] <= pivot){
			low++;
		}
		array[high] = array[low];
	}
	array[low] = pivot;
		
	return low;
}
void QuickSort(int* array, int low, int high){
	if (low < high){
	 	int pivot = sort(array, low, high);
		QuickSort(array, low, pivot-1);
		QuickSort(array, pivot+1, high);
	}
}

 
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
 
    int mid = 0;
    int low = 0;
    int high = 0;
    int sum = 0;
    *returnSize = 0;

    if (numsSize < 3)
    {
        return NULL;
    }
    QuickSort(nums, 0, numsSize-1);

    int** ret = (int**)malloc(sizeof(int*) * numsSize * numsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize);

    while (nums[mid] <= 0 && mid < numsSize-2)
    {
        low = mid+1;
        high = numsSize - 1;
        while (low < high)
        {
            sum = nums[low] + nums[mid] + nums[high];
            if (sum == 0)
            {
                ret[*returnSize] = (int*)malloc(sizeof(int) * 3);
                ret[*returnSize][0] = nums[mid];
                ret[*returnSize][1] = nums[low];
                ret[*returnSize][2] = nums[high];
                (*returnColumnSizes)[*returnSize] = 3;

                (*returnSize)++;

                while (low < high && nums[low] == nums[++low]);
                while (low < high && nums[high] == nums[--high]);
            }
            else if (sum < 0)
            {
                low++;
            }
            else
            {
                high--;
            }

        }
        while (mid < numsSize-2 && nums[mid] == nums[++mid]);
    }

    return ret;
}
```