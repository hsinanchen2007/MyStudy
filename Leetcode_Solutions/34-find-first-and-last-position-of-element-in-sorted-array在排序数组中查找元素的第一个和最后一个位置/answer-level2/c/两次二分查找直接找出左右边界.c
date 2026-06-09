```
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ret=(int *)malloc(sizeof(int)*2);
    ret[0]=-1;
    ret[1]=-1;
    *returnSize=2;
    if(numsSize==0||target<nums[0]||target>nums[numsSize-1]){        
        return ret;
    }
    int left=0, right=numsSize-1, mid=0, head=0, tail=0;
    while(left<=right){
        mid=(left+right)/2;
        if(nums[mid]>=target){
            right=mid-1;
        }
        else{
            left=mid+1;         //mid存的就是第一个>=target的那个值的索引
        }
    }
    head=left;
    left=0, right=numsSize-1, mid=0;
    while(left<=right){
        mid=(left+right)/2;
        if(nums[mid]<=target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    tail=right;
    if(nums[head]==target){     //存在这个数
        ret[0]=head;
        ret[1]=tail;
    }
    return ret;
}
```
![image.png](https://pic.leetcode-cn.com/84536ece440f08f9e646edce296c6c32d96ba8f3517907ae6db33c89afa02f87-image.png)
