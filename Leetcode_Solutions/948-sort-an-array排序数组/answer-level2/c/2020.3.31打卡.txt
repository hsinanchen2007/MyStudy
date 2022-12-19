### 解题思路
一手quicksort

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void quicksort(int *nums,int start,int end)
{
    int left=start;
    int right=end-1;
    int mid=*(nums+end);
    while(left<right)
    {
        while(left<right && *(nums+left)<mid) left++;
        while(left<right && *(nums+right)>=mid) right--;
        if(left<right)
        {
            int tmp=*(nums+left);
            *(nums+left)=*(nums+right);
            *(nums+right)=tmp;
        }                
    }
    if(*(nums+left)>mid)
    {
        *(nums+end)=*(nums+left);
        *(nums+left)=mid;
    }
    if(left>start)
    {
        quicksort(nums,start,left);
    }
    if(left<end-1)
    {
        quicksort(nums,left+1,end);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize){

    quicksort(nums,0,numsSize-1);
    *returnSize=numsSize;
    return nums;
}
```