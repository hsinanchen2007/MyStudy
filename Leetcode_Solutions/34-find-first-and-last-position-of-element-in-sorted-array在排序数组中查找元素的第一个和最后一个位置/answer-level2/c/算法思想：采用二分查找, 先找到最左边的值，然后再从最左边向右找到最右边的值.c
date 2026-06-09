### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *result = malloc(sizeof(int)*2);
    int low = 0,high = numsSize-1,mid;
    
    if(numsSize==0){
        result[0]=-1;
        result[1]=-1;
        return result;
    }
    
    if(nums[low]==target){
        result[0]=low;
    }
    else{
        while(low+1<high){
            mid = low+(high-low)/2;
            if(nums[mid]<target){
                low = mid;
            }
            else{   //在坐分区中查找
                high=mid;
            }
        }
        result[0]=high;
        low=high;
        high=numsSize-1;
    }

    if(nums[high]==target){
        result[1]=high;
    }
    else{
        while(low+1<high){
            mid = low+(high-low)/2;
            if(nums[mid]>target){
                high=mid;
            }
            else{//继续在左分区中查找
                low=mid;
            }
        }
        result[1]=low;
    }

    if(nums[result[0]]!=target||nums[result[1]]!=target){
        result[0]=-1;
        result[1]=-1;
    }

    return result;
}
```