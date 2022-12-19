### 解题思路
考虑问题要周全，这里相同的数字不能重复

### 代码

```c
int thirdMax(int* nums, int numsSize){
    int first,second,third;
    int i;
    int min=nums[0];
    for(i=1;i<numsSize;i++){//找最小，也可用min=INT_MIN来代替
        if(nums[i]<min){
            min=nums[i];
        }
    }
    first=second=third=min;
    for(i=0;i<numsSize;i++){//分类讨论，细节要周全
        if(nums[i]>first){
            third=second;
            second=first;
            first=nums[i];
        }
        else if(nums[i]>second&&nums[i]!=first){
            third=second;
            second=nums[i];
        }
        else if(nums[i]>third&&nums[i]!=first&&nums[i]!=second){//这里很关键
            third=nums[i];
        }
    }
    if(third==second||second==first){
        return first;
    }
    return third;
}
```