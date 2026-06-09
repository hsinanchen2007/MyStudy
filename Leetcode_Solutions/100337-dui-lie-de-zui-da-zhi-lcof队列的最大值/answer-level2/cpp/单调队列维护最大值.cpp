题目描述应该有点问题，一个队列入队出队取最大值都是O(1)，优先队列不就被完爆了吗，均摊时间复杂度O(1)应该是可以的。
我的思路是除了一个必要的记录队列的数组**a**以及它的头尾指针**la,ra**，再加一个记录队列后缀最大值的数组**ma**和头尾指针**lm,rm**。
1. 入队操作：更新a和ma，从后往前把ma中小于入队元素的值赋值成入队元素
2. 出队操作：更新下a和ma的边界
3. 询问最大值：返回ma的第一个元素，ma为空就返回-1

任何一个操作结束两个队列指针总是相同的，且元素是先进先出，ma数组单调不增，因此就是单调队列。

另外均摊复杂度计算就是假设我这样最坏情况有k次，每次入队(n/k)-1个递减元素之后再放入1个很大的元素，这样push_back要循环n/k-1次去更新后缀最大值，因此总的复杂度就是k*(n/k-1),而最多n次操作，所以均摊复杂度就是O(k*n/k/n)=O(1)

```
class MaxQueue
{
public:
    const static int N = 10001;
    int a[N], ma[N], la, ra, lm, rm;

    MaxQueue()
    {
        la = ra = lm = rm = 0;
    }

    int max_value()
    {
        if(lm < rm)
            return ma[lm];
        else
            return -1;
    }

    void push_back(int value)
    {
        a[ra++] = value;
        int trm = rm;
        while (lm < rm && ma[rm - 1] < value)
            ma[--rm] = value;
        ma[trm++] = value;
        rm = trm;
    }

    int pop_front()
    {
        if(la < ra)
        {
            int ret = a[la++];
            while (lm < rm && lm < la)
                ++lm;
            return ret;
        }
        else
            return -1;
    }
};

```
