与官方题解思路相同
```
int search(int* nums, int numsSize, int target){
    
    if(numsSize==0){
        return -1;
    }
    int left=0, right=numsSize-1, mid;
    //第一次查找数组最先的元素
    if(nums[numsSize-1]<nums[0]){
        while(left<right){              //这种限制条件最终的点落在left=right上
            mid=(left+right)/2;
            if(nums[mid]>nums[right]){
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        //确定定位在哪一段
        if(target>=nums[0]){
            right=left-1;left=0;        //left得后赋值，因为right的值用到了right的值
            }
        else{
            left=left;right=numsSize-1;
        }
    }
    //查找位置
    while(left<right){              
        mid=(left+right)/2;
        if(nums[mid]<target){
            left=mid+1;
        }
        else{
            right=mid;
        }
    }
    //查找完成
    if(nums[left]==target){
        return left;
    }
    else return -1;
}
```
![image.png](https://pic.leetcode-cn.com/57c43ee84d7392935b7661a1717581e44a83a5dbee09c61b83a853d4d33da11d-image.png)
