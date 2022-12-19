### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    *returnSize=numsSize;
    int i;
    int *ret=(int *)malloc(sizeof(int)*(numsSize+1));
    for(i=0;i<numsSize;i++){
        if(i==index[i]){
            ret[index[i]]=nums[i];
        }else{
            for(int j=i+1;j>index[i];j--){
                ret[j]=ret[j-1];
            }
            ret[index[i]]=nums[i];
        }
    }
    return ret;
}
```