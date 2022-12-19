### 解题思路
该题利用桶排序的方法进行求解，解题思路如下:
* 建立并初始化桶排序数组
* 循环遍历原数组，找到符合要求的数组元素
* 返回结果

Note: 该解法简单，但没什么技术含量，不推荐。

本题的时间复杂度为O(N)

### 代码

```c
int findSpecialInteger(int* arr, int arrSize)
{
    int max = arr[arrSize-1];
    int tmp[max+1];
    for(int k =0; k<=max;k++)
    {
        tmp[k] = 0;
    }

    int i=0;
    for(i=0; i<arrSize; i++)
    {
        tmp[arr[i]]++;
        if((tmp[arr[i]] != 0) && (arrSize/tmp[arr[i]] < 4))
        {
            break;
        }
    }

    return arr[i];
}
```