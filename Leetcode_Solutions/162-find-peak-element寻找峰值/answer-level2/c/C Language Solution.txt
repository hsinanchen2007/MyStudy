__1、思路__
（1）首先处理数组元素个数是1、2、3的情况
（2）然后处理数组边界值可能是峰值的情况
（3）然后根据峰值大于左右值的特点，一次for循环解决问题

```
int findPeakElement(int* nums, int numsSize){
    if(numsSize<=0){
        return NULL;
    }
    if(numsSize==1){
        return 0;
    }
    if(numsSize==2){
        return nums[0]>nums[1]?0:1;
    }
    if(numsSize==3){
        if(nums[1]>nums[0]&&nums[1]>nums[2]){
            return 1;
        }
        return nums[0]>nums[2]?0:2;
    }
    if(nums[0]>nums[1]){
        return 0;
    }
    int temp;
    for(int i=1;i<numsSize-1;i++){
        if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]){
            temp = i;
            break;
        }
        if(i==numsSize-2){
            return numsSize-1;
        }
    }
    return temp;
}
```
菜鸟的水平，还望大佬们勿喷！：）