### 解题思路
1. 将已有序列和下一个待处理的数字当作两个元素。
2. 注意：待处理的数字 + 负数序列，此时负数序列可以抛弃，因为他对我们后面序列的增大有副作用。而这个待处理的数字就是我们后面序列的第一个元素。




### 代码

```c
int maxSubArray(int* nums, int numsSize){

    if (numsSize == 0)
    {
        return NULL;
    }

    int maxNum = nums[0];
    int sum = 0;
    int i = 0;
    int sumMax = nums[0];

    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] > maxNum)
        {
            maxNum = nums[i];
        }

        sum += nums[i];//累加

        if (sumMax < sum)//记录最大的序列和
        {
            sumMax = sum;
        }

        if (sum < 0)//序列和小于0，抛弃
        {
            sum = 0;
        }
    }

    if (sumMax < maxNum)//没有正数序列和的问题。没有正数，则sum == 0，显然是错的。此时maxNum记录最大的负数。
    {
        sumMax = maxNum;
    }

    return sumMax;

}
```