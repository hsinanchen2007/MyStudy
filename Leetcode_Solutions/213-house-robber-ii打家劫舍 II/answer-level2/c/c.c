### 解题思路
...

### 代码

```c
int MaxNum(int num1, int num2)
{
    if(num1 >= num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}

int GetMaxValue(int* nums, int numsSize)
{
    int i;
    int *numTemp;

    numTemp = (int *)malloc(sizeof(int) * numsSize);

    numTemp[0] = nums[0];
    numTemp[1] = MaxNum(nums[0], nums[1]);
    for(i = 2; i < numsSize; i++)
    {
        numTemp[i] = MaxNum(numTemp[i-1], numTemp[i-2] + nums[i]);
    }

    return numTemp[numsSize - 1];

}

int rob(int* nums, int numsSize)
{
    int a;
    int b;
    int ret;
    int *temp;

    if(numsSize == 0)
    {
        return 0;
    }

    if(numsSize == 1)
    {
        return nums[0];
    }

    if(numsSize == 2)
    {
        return MaxNum(nums[0], nums[1]);
    }

    if(numsSize == 3)
    {
        ret = MaxNum(nums[0], nums[1]);
        return (MaxNum(ret, nums[2]));
    }

    a = GetMaxValue(nums, numsSize - 1);
    temp = ++nums;
    b = GetMaxValue(temp, numsSize - 1);
    return MaxNum(a, b);
}
```