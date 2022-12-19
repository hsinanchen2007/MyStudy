### 解题思路
该题难度较低，解决思路如下：
* 入参检查
* 循环遍历每个数组元素，并循环判断该数与10的余数，获取该数组元素的位数
* 判断位数为奇数还是偶数

本题的时间复杂度为O(N^2),空间复杂度为O(1)

### 代码

```c
int findNumbers(int* nums, int numsSize)
{
    //入参检查
    if(!nums)
    {
        return 0;
    }

    //循环遍历数组每个元素
    int num = 0;
    int tmp = 0;
    int bit_num = 0;
    for(int i =0; i < numsSize; i++)
    {
        tmp = nums[i];
        //计算数字的位数
        for(bit_num=1; tmp%10!=tmp; bit_num++)
        {
            tmp = tmp/10;
        }
        //判断数字位数
        if(bit_num%2 == 0)
        {
            num++;
        }
    }
    return num;
}
```