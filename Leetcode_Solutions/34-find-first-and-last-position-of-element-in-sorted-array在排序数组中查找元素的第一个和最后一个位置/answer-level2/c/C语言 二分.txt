
    第一次写题解。其实这个题我觉得二分法是最好理解的，其实就和二分法找一个数组中仅出现一次的数字差不多，差别就在于当二分到的那个数字和目标相同时的操作，因为要找出最开始的位置和最结尾的位置，所以就用两个递归。
    在找最开始位置时，只需要在二分到的数字等于目标时，将这个数字之前的所有数字再进行递归，如果返回-1，那么就说明这次的位置就是最开始的位置，不然就返回递归的值。所以也就是只需要加个if判断就可以了。   
    最后的结尾位置也一样，只不过是对这个数字之后的所有数字进行递归，同样加判断条件。

    但是不知道为什么，明明我在函数的开头加了判为-1的条件，但是就是会报错，明明我自己电脑上可以的说，弄得我非得在递归之前就在判断一次。。。。

```
int START(int *nums,int start,int end,int target){
    if(start>end||start<0||end<0){
        return -1;
    }
    
    if(nums[start]>target){
        return -1;
    }


    int mid=(start+end)/2;
    if(target>nums[mid]){
        if(mid+1>end)return -1;
        return START(nums,mid+1,end,target);
    }
    else if(target<nums[mid]){
        if(start>mid-1)return -1;
        return START(nums,start,mid-1,target);
    }
    else{
        if(target == nums[mid]){
            int t=0;
            if(start>(mid-1))
            {
                t=-1;
            }
            else{
               t= START(nums,start,mid-1,target);
            }
            if(t!=-1){
                return t;
            }
            else{
                return mid;
            }
        }
    }
    return -1;
}


int END(int *nums,int start,int end,int target){
    if(nums[start]>target){
        return -1;
    }
    if(start>end){
        return -1;
    }

    int mid=(start+end)/2;
    if(target>nums[mid]){
        if(mid+1>end)return -1;
        return END(nums,mid+1,end,target);
    }
    else if(target<nums[mid]){
        if(start>mid-1)return -1;
        return END(nums,start,mid-1,target);
    }
    else{
        if(target == nums[mid]){
            int t=0;
            if(mid+1>end)
            {
                t=-1;
            }
            else{
                t=END(nums,mid+1,end,target);
            }

            if(t!=-1){
                return t;
            }
            else{
                return mid;
            }
        }
    }
    return -1;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *line =(int*)malloc(sizeof(int)*2);
    if(numsSize==0){
        line[0]=-1;
        line[1]=-1;
        *returnSize=2;
        return line;
    }
    
    
    line[0]=START(nums,0,numsSize-1,target);
    line[1]=END(nums,0,numsSize-1,target);
    *returnSize=2;
    return line;
}
```
