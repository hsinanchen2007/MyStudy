### 解题思路
整体思路是这次的多余值要传递给下一个，sum会在下一个进行计算，另外要注意两个数的距离和多余的树之间的比较。

### 代码

```c
int minIncrementForUnique(int *A, int ASize)
{
    int array[40001];
    memset(array, 0, sizeof(int) * 40001);
    for (int i = 0; i < ASize; i++)
    {
        array[A[i]]++;
    }
    int markCount = 0, sum = 0, lastI = 0;
    //markCount是记录下一次
    for (int i = 0; i <= 40000; i++)
    {
        if (array[i] > 0) //1也要停下，因为如果连续赋值为一的话，会作为一个bug
        {
            if (markCount != 0) //说明上一个数有多余的要传递
            {
                if (i - lastI > markCount)
                    sum = sum + (markCount + 1) * markCount / 2;
                else //也有可能空间不够大,下面的
                {
                    sum = sum + ((i - lastI - 1) + 1) * (i - lastI - 1) / 2;
                    //上面这个是中间有空的话给的
                    //下面是空不够剩下的要到下一个地方
                    sum = sum + (markCount - (i - lastI - 1)) * (i - lastI);
                }
            }
            if (i - lastI - 1 < markCount && markCount != 0)
                markCount = array[i] - 1 + markCount - (i - lastI - 1); //多余的数据 下次要传递
            else
                markCount = array[i] - 1;
            lastI = i;
        }
    }
    sum = sum + (markCount + 1) * markCount / 2;
    return sum;
}

```