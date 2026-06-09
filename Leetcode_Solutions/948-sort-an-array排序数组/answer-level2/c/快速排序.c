### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    if (numsSize <= 1){
        *returnSize = 1;
        return nums;
    }

	int i=0,j=numsSize-1,tmp;
    // 冒泡排序效率不行
	// for(i=0;i < numsSize - 1;i++){
	// 	for(j=0;j<numsSize - i - 1; j++){
	// 		if (nums[j] > nums[j+1]){
	// 			tmp = nums[j];
	// 			nums[j] = nums[j+1];
	// 			nums[j+1] = tmp;
	// 		}
	// 	}
	// }

    //用快速排序
    int key = nums[0];
    for(i=0,j=numsSize-1; i < j;){
        while(nums[j] >= key && i < j){
            j--;
        }
        if (i == j) break;
        tmp = nums[j];
        nums[j] = nums[i];
        nums[i] = tmp;

        while(nums[i] <= key && i < j){
            i++;
        }
        if (i == j) break;
        tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    sortArray(nums, i, &tmp);
    sortArray(nums+i+1, numsSize - i - 1, &tmp);

	*returnSize = numsSize;
	return nums;
}

```