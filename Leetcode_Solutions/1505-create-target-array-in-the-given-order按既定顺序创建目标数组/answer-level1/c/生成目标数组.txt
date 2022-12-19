### 解题思路
此处撰写解题思路
注意：c语言的returnSize要填，这个是指针类型，一开始我还以为返回数组是它，必须反馈！
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    int*target = (int*)malloc(numsSize*sizeof(int));
    int i,j;
    for(i=0;i<numsSize;i++){
        for(j=numsSize-1;j>index[i];j--){
            target[j]=target[j-1];
        }
        target[j]=nums[i];
    }
    *returnSize=numsSize;
    return target;
}
```