### 解题思路
此处撰写解题思路

### 代码

```c


int thirdMax(int* nums, int numsSize){
    if(numsSize < 3)
        return nums[0] < nums[1] ? nums[1] : nums[0];
    int firstMax, secondMax, thirdMax;
    int min = nums[0]; 
    int i;
    for(i = 0; i < numsSize; ++i)
    {
        if(min > nums[i])
            min = nums[i];
    }
    firstMax = min;
    secondMax = min;
    thirdMax = min;
    for(i = 0; i < numsSize; ++i)
    {
        if(firstMax < nums[i])
            firstMax = nums[i];
    }

    for(i = 0; i < numsSize; ++i)
    {
        if(secondMax < nums[i] && nums[i] < firstMax)
            secondMax = nums[i];
    }

    if(firstMax == secondMax)
        return firstMax;

    for(i = 0; i < numsSize; ++i)
    {
        if(thirdMax < nums[i] && nums[i] < secondMax)
            thirdMax = nums[i];
    }

    if(secondMax == thirdMax)
        return firstMax;
    
    return thirdMax;
}


```