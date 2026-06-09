### 解题思路
先后移，后插入（赋值）。


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    int * array = (int *)malloc(numsSize * sizeof(int));
    for(int i=0;i<indexSize;i++){
        for(int j=indexSize-1;j>index[i];j--){
            array[j]=array[j-1];
        }
        array[index[i]]=nums[i];
    }
    *returnSize=indexSize;
    return array;
}
```