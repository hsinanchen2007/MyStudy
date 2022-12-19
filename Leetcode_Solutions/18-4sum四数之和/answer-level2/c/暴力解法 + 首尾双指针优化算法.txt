### 解题思路
此处撰写解题思路
方法1：暴力解法
（1）先使用qsort快速排序，为后续去重做铺垫；
（2）4个for循环遍历查找；遍历时，如遇到已遍历元素，则跳过；

方法2：首尾双指针优化算法
（1）先使用qsort快速排序，为后续去重做铺垫；
（2）固定两个数（即两层for循环），另外两个数采用首尾双指针遍历查找；

注意：二维指针的内存空间分配方法；先分配行，再分配列；

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int cmp(const void *a, const void *b) {
     return *(int*)a - *(int*)b;
 }

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int** returnArray = (int **)malloc(sizeof(int *) * (numsSize * numsSize));
    *returnSize = 0;

    //排序
    qsort(nums, numsSize, sizeof(int), cmp);
    
    for (int i = 0; i < numsSize; i++) {
        if ((i > 0) && (nums[i] == nums[i - 1])) {
            continue;
        }
        for (int j = i + 1; j < numsSize; j++) {
            if ((nums[j] == nums[j - 1]) && (j > i + 1)) {
                continue;
            }

            int leftIndex, rightIndex, twoSum;
            leftIndex = j + 1;
            rightIndex = numsSize - 1;
            twoSum = nums[i] + nums[j];

            while (leftIndex < rightIndex) {
                if ((nums[leftIndex] + nums[rightIndex]) < (target - twoSum)
                    || ((leftIndex > j + 1) && (nums[leftIndex] == nums[leftIndex - 1]))) {
                    leftIndex++;
                } else if ((nums[leftIndex] + nums[rightIndex]) > (target - twoSum)
                    || ((rightIndex < numsSize - 1) && (nums[rightIndex] == nums[rightIndex + 1]))) {
                    rightIndex--;
                } else {
                    returnArray[*returnSize] = (int *)malloc(sizeof(int) * 4);
                    returnArray[*returnSize][0] = nums[i];
                    returnArray[*returnSize][1] = nums[j];
                    returnArray[*returnSize][2] = nums[leftIndex];
                    returnArray[*returnSize][3] = nums[rightIndex];
                    (*returnSize)++;
                    leftIndex++;
                    rightIndex--;
                }
            }
        }
    }

    *returnColumnSizes = (int *)malloc(sizeof(int) * (* returnSize));
    for (int index = 0; index < *returnSize; index++) {
        returnColumnSizes[0][index] = 4;
    }
    return returnArray;
}
```