### 解题思路
二分查找合理设置条件

### 代码

```c

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *result= (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    result[0]=result[1]=-1;
    int left=0;int right=numsSize-1;
    int mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(nums[mid]==target&&(mid==0||nums[mid-1]<target)){result[0]=mid;break;}
        else if(nums[mid]<target){left=mid+1;}
        else{right=mid-1;}
    }
    if(result[0]==-1){return result;}
    left=0;right=numsSize-1;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(nums[mid]==target&&(mid==numsSize-1||nums[mid+1]>target)){result[1]=mid;break;}
        else if(nums[mid]<=target){left=mid+1;}
        else{right=mid-1;}
    }    
    return result;
}


```