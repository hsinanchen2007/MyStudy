### 解题思路
举个例子，比如现在遍历了4个偶数0,2,4,6，发现小于遍历三个的1,3,5的奇数，则把偶数总数记为奇数，
当遍历第5个偶数时，最大的值就是1,3,5,8，而不是02468或1357
### 代码

```c
int rob(int* nums, int numsSize){
    int i;
    int num1 = 0, num2 = 0;

    for (i = 0; i < numsSize; i++) 
    {
        if (i % 2 == 0)
        {
            num1 += nums[i];
            num1 = num1 > num2 ? num1 : num2;
        }
        else
        {
            num2 += nums[i];
            num2 = num1 > num2 ? num1 : num2;
        }
    }

    return num1 > num2 ? num1 : num2;
}
```