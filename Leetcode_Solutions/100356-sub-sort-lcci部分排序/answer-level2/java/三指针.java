第一个指针指向从头开始最长正确顺序
第二个指针指向从头到当前位置的最大值处在的位置
第三个指针指向最后一个出错的点

思路大致为遍历一遍数组，当前值大于等于最大值，第一个指针就一直往前，直到出现一个值比最大值小，就和第一个指针指向的值比较大小，如果正确的顺序的最大值比当前值大，那么第一个指针就得往回走，不然不需要往前走，最后一个出错的点就指向了当前值。

第一个指针往回走可以用二分查找的，不过懒得写了……
```
class Solution {
    public int[] subSort(int[] array)
    {
        int a = 0;
        int b = 0;
        int c = 0;
        boolean big = false;
        for (int i = 0 ; i < array.length;i++)
        {
            if (array[i] < array[b])
            {
                c = i;
                if (array[a] > array[i])
                {
                    for (int j = a; j > 0;j--)
                    {
                        if (array[j - 1] <= array[i])
                        {
                            break;
                        }
                        a--;
                    }
                }
                big = true;
            }
            if (array[i] >= array[b])
            {
                b = i;
                if (!big)
                {
                    a = i;
                }
            }
        }
        if (!big)
        {
            return new int[]{-1,-1};
        }
        return new int[]{a,c};
        
    }
}

```
