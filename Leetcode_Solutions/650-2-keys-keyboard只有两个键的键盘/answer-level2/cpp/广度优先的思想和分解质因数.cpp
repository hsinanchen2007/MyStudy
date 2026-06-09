### 解题思路
我想出了两种方法，这里展示了第一种。
首先想到的是复制粘贴一次得到2，从n=2开始构建二叉树，一个分支是以直接粘贴得到的结果，这条边权值为1，另一个分支是复制粘贴得到的结果，这条边权值为2，从而通过深度优先搜索值为n的结点得到最小次数。基于这种思想经过变形、改进和优化后写出了下面所展示的代码，但是性能仍然不够理想，所以就有了第二种方法。
以t代表次数，c代表当前复制的A的数量，通过分析，最后一步执行的必然是粘贴，则最后一步的前一步执行完后的数量必然是(x-1)n/x,c=n/x,其中x>1;进一步可以得出结论可以由n/x经过一次复制和x-1次粘贴得到n，共x步;同理，也可以由n/(x*y)经过y步得到n/x，n/(x*y)经过x+y步得到n;则可以推出可以由1经过x+y+z+....步得到n，其中x*y*z*....=n；也就是说如果将n进行因数分解，将所得的因数相加就是次数，现在的问题是如何使次数最小，也就是t=x+y+z+....最小，这里规定每个因数都大于1，因为等于1是没有意义的，这里有个式子：当x,y都大于1时，x+y<xy.对应到我们这里就是把n因数分解得越“细”，步数t就越小，分解到最“细”，也就是分解到全部因数都是质数的时候t最小，所以这个问题的本质就是分解质因数，将分解到的全部质因数相加就是最小步数，分解质因数的算法网上有很多，这里就不赘述了，这两种方法限于篇幅许多细节没有说到，结合我说的认真思考后大家应该都能想明白。
本人水平有限，有不对的地方还请各位批评指教。


### 代码

```cpp
class Solution {
public:
  class Node
{
public:
    int number;
    int copy;

    Node(int aNumber, int aCopy)
    {
        number = aNumber;
        copy = aCopy;
    }
};

int minSteps1(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 2;
    list<Node> t[3];
    t[0].push_back(Node(2, 1));
    int index, next, nextnext;
    for (int i = 0; i < n; i++)
    {
        index = i % 3;
        next = (i + 1) % 3;
        nextnext = (i + 2) % 3;
        t[nextnext].clear();
        for (auto &r : t[index])
        {
            if (r.number + r.copy < n)
                t[next].push_back(Node(r.number + r.copy, r.copy));
            else if (r.number + r.copy == n)
                return i + 3;
            if (r.number * 2 < n)
                t[nextnext].push_back(Node(r.number + r.number, r.number));
            else if (r.number * 2 == n)
                return i + 4;
        }
    }
    return -1;
}

};
```