### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    int *ret,i,j,k=0;
    ret=(int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<indexSize;i++){
        if(index[i]<k){
            for(j=k;j>index[i];j--)
                ret[j]=ret[j-1];
        }
        ret[index[i]]=nums[i];
        k++;
    }
    *returnSize=k;
    return ret;
}
```