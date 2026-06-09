### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize)
{
    int * target=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++)
    {
        int t=index[i];
        int k=numsSize-1;
        while(k!=t)
        {
            target[k]=target[k-1];
            k--;
        }
        target[index[i]]=nums[i];
    }
    *returnSize=numsSize;
    return target;

}
```