### 解题思路
又学到一个新算法。
其实还是因为隐藏条件，
假设众数为1，非众数为-1，将所有数字相加，结果应该大于0.
遍历一遍数组，当和小于0时，则更换众数，求出最后大于0的数字即可。

还是有点难理解，啊哈哈

### 代码

```c
int majorityElement(int* nums, int numsSize){
    if(numsSize<=2)
    {
        return nums[0];
    }

    //先排序
    int i=0,j=0,temp=nums[0],count=1;
/*    for(i=0;i<numsSize;i++)
    {
        for(j=numsSize-1;j>i;j--)
        {
            if(nums[j]<nums[j-1])
            {
                temp=nums[j];
                nums[j]=nums[j-1];
                nums[j-1]=temp;
            }
        }
    }
    return nums[numsSize/2];
    */
    for(i=1;i<numsSize;i++)
    {
        if(temp!=nums[i])
        {
            count--;
            if(count==0)
            {
                count=1;
                temp=nums[i];
            }
        }
        else
        {
            count++;
        }
    }
    return temp;
}
```