### 解题思路
该题是找出数组的最小值，解题思路如下：
* 入参检查
* 循环遍历数组，找出最小值，并返回

本题的时间复杂度为O(N)，空间复杂度为O(1)。

### 代码

```c
int minArray(int* numbers, int numbersSize)
{
    //入参检查
    if(!numbers)
    {
        return 0;
    }
    //查找数组的最小值
    int min = numbers[0];
    for(int i=0; i<numbersSize; i++)
    {
        if(min >= numbers[i])
        {
            min = numbers[i];
        }
    }
    return min;
}
```