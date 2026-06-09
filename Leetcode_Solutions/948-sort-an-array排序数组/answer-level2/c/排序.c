### 解题思路
l冒泡 与 快排

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 /*
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize=numsSize;
    int temp;
    for(int i=0;i<numsSize;i++)
        for(int j=0;j<numsSize-i-1;j++)
        {
            if(nums[j]>nums[j+1]){
                temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    return nums;
}
*/
int cmpfunc (const void * a, const void * b)
{
return ( *(int*)a - *(int*)b );
}
int* sortArray(int* nums, int numsSize, int* returnSize)
{
* returnSize = numsSize;
qsort(nums, numsSize, sizeof(int), cmpfunc);
return nums;
}


JAVA 雪姨的  非比较方法
/*
class Solution {
    public int[] sortArray(int[] nums) {
        int max = -50001, min = 50001;
        for (int num: nums) {
            max = Math.max(num, max);
            min = Math.min(num, min);
        }


        int[] counter = new int[max - min + 1];
        for (int num: nums) {
            counter[num - min]++;
        }

        int idx = 0;
        for (int num = min; num <= max; num++) {
            int cnt = counter[num - min];
            while (cnt-- > 0) {
                nums[idx++] = num;
            }
        }
        return nums;
    }
}
*/ 