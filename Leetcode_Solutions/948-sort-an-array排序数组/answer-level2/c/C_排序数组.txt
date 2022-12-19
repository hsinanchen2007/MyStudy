### 解题思路
快速排序（记）
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void fastSort(int* Nums,int Low,int High)
{
    if(Low<High)
    {
        int i=Low,j=High,temp=Nums[Low];
        while(i!=j)
        {
            while(i<j&&Nums[j]>temp)--j;
            if(i<j)Nums[i++]=Nums[j];
            while(i<j&&Nums[i]<temp)++i;
            if(i<j)Nums[j--]=Nums[i];
        }
        Nums[i]=temp;
        fastSort(Nums,Low,i-1);
        fastSort(Nums,i+1,High);
    }
}
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize=numsSize;
    fastSort(nums,0,numsSize-1);
    return nums;
}
```