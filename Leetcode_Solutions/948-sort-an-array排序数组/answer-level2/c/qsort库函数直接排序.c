### 解题思路
C语言的排序一般都比较麻烦，常见的冒泡之类的效率都比较低。最近看了qsort函数，写起来比较简单。效率也一般般吧

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int compare(const void *a, const void *b)
 {
     return *(int*)a - *(int*)b;
 }

int* sortArray(int* nums, int numsSize, int* returnSize){

    *returnSize = numsSize;

    
    qsort(nums, numsSize, sizeof(int), compare);
    return nums;
}
```