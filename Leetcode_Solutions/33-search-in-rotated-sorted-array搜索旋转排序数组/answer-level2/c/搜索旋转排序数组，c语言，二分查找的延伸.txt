### 解题思路
方法一：每一次二分查找都将数组分为一半有序一半无序，如果target在有序的一半就二分查找有序的一半，反之查找另一半

方法二：两遍二分查找，第一遍找出旋转的枢纽(要注意如果数组没有旋转的情况)，两边都是有序数列。第二遍在target可能所在的那部分二分查找。

### 代码

```c
//方法一：每一次二分查找都将数组分为一半有序一半无序，如果target在有序的一半就二分查找有序的一半，反之查找另一半
int search(int* nums, int numsSize, int target){
    if(numsSize == 0)
        return -1;
    int low=0, high=numsSize-1, mid;
    while(low <= high){
        mid = (low+high)/2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[mid]>=nums[0]){          //mid前边有序
            if(nums[mid]>target && target>=nums[0]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        if(nums[mid]<=nums[numsSize-1]){    //mid后边有序
            if(nums[numsSize-1]>=target && target>nums[mid]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }   
    }
    return -1;
}
```

```
//方法二：两遍二分查找，第一遍找出旋转的枢纽(要注意如果数组没有旋转的情况)，两边都是有序数列。第二遍在target可能所在的那部分二分查找。
int search(int* nums, int numsSize, int target){
    if(numsSize<1){
        return -1;
    }
    if(numsSize == 1){
        return (nums[0]==target?0:-1);
    }
    int low=0,high=numsSize-1,mid=-1;
    while(low<=high){
        mid = (low+high)/2;
        if(nums[mid]>nums[mid+1]){
            break;
        }else if(nums[mid]<nums[0]){
            high  = mid-1;
        }else if(nums[mid]>nums[numsSize-1]){
            low = mid+1;
        }else{
            mid = -1;                 //如果数组没有旋转，仍然是升序。
            break;                  
        }
    }
    int pivot = mid;
    if(target>nums[numsSize-1] && target<nums[0]){
        return -1;
    }else if(target>nums[numsSize-1]){
        low = 0;
        high = pivot;
    }else{
        low = pivot+1;
        high = numsSize-1;
    }
    while(low<=high){
        mid = (low+high)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid]<target){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}
```
