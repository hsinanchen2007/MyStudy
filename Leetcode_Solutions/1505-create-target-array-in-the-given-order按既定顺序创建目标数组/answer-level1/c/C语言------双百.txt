### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
int*ret=(int*)malloc(sizeof(int)*(indexSize+numsSize));
int i=0,j=0,max=0,k;
while(i<numsSize&&j<indexSize){
if(index[j]>max){
ret[index[j]]=nums[i];
max++;
}
else{
    for(k=max;k>index[j];k--)
    ret[k]=ret[k-1];
    max++;
    ret[index[j]]=nums[i];
}
i++;j++;
}
while(i<numsSize)
ret[max++]=nums[i++];
*returnSize=max;
return ret;
}
```