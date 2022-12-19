### 解题思路
此题核心算法思路为贪心算法。

1.首先将序列分为三部分，左（单调增），中，右（单调增）

2.统计中间序列的最大最小值

3.扩充中间序列。
    这里使用了贪心的思路，即如果左侧最大值大于中间的最小值，则一定会被中间序列包括；
    同理，如果右侧最小值大于中间的最大值，则一定会被中间序列包括。
4.循环执行3，直至没有新的数据被包括到中间序列

注意，中间序列的最大最小值初始化有个技巧，即初始为array[ll + 1],为了避免中间序列为空的情况。


![image.png](https://pic.leetcode-cn.com/b55dd781c7ee8ac241456efe651a84b3bc6b6262ebdd6d56c77b74122a872906-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

int ret[2];

//【算法思路】排序+双指针。
int* subSort(int* array, int arraySize, int* returnSize){
    if(arraySize <= 1)
    {
        ret[0] = -1;
        ret[1] = -1;

        *returnSize = 2;
        return ret;
    }

    //先找到rr，rr是右侧第一个满足连续递增的位置
    int base = array[0];
    int ll, rr;

    bool find = false;

    for(int i = 1; i < arraySize; i++)
    {
        if(array[i] >= base)
        {
            base = array[i];
        }
        else
        {
            ll = i - 1;
            find = true;
            break;
        }
    }

    if(find == false)
    {
        ret[0] = -1;
        ret[1] = -1;

        *returnSize = 2;
        return ret;
    }

    base = array[arraySize  - 1];

    for(int i = arraySize - 2; i >= 0; i--)
    {
        if(array[i] <= base)
        {
            base = array[i];
        }
        else
        {
            rr = i + 1;
            break;
        }
    }

    //找到中间序列的最大最小值
    int max = array[ll + 1];
    int min = array[ll + 1];

    for(int i = ll + 1; i < rr; i++)
    {
        max = MMAX(max, array[i]);
        min = MMIN(min, array[i]);
    }



    printf("ll = %d, rr = %d, max = %d, min = %d\n", ll, rr, max, min);

    //此时[0, ll]和[rr, Size - 1]有序
    bool proc = true;
    while(proc == true)
    {
        proc = false;

        //如果左边的上边界大于中间数据最小值，则一定会被包括，右边数据的下边界如果小于中间的最大值，则一定会被包括
        if(ll >= 0 && array[ll] > min)
        {
            max = MMAX(max, array[ll]);
            ll--;

            proc = true;
        }

        if(rr < arraySize && array[rr] < max)
        {
            min = MMIN(min, array[rr]);
            rr++;

            proc = true;
        }

        //printf("ll = %d, rr = %d, max = %d, min = %d\n", ll, rr, max, min);
    }

    ret[0] = ll + 1;
    ret[1] = rr - 1;

    *returnSize = 2;
    return ret;
}
```