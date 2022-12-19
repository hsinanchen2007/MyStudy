· 结果是4ms的100%和8.7M的100%。

· 思路：
1. 动态创建一个二维数组，一个保留列宽的一维数组，每次需要增加子列的时候就给前面二维数组的子数组动态分配相应的空间，分配的规律很简单，你会发现他除以2的话子列长度就是2，除以3子列长度就是3，以此类推，这部分在下面重点的for循环那里；

2. 子列数计数器：其实这个本来是不需要的，没办法人家的题目要求子列是从最长到最短，没有这第一个while循环配合的话就会导致结果反了，他不认啊。如果用最后再反转数组的方法无疑是最蠢的，但一时我也没想到怎么用1个while就可以将他从宽到窄的排列，只好增加一个小小的循环，然后再把计数器原路返回（相当于把前面计数过程的结果拿来反过来计数一遍），便可以得到我想要的排列；

3. 数学思想的话，我看有些是用奇偶来分的（一开始我也是这么想的），但我也看见其他的思路似乎更有亮点，就是统一成只需变动我的target（在代码中是变动t，从t 到target），在这个随着i--而t+的过程中我的t和i自然而然就会经历奇数和偶数，但并不是把t/i当做对称轴即子列中心，而是作为子列的起点，依次增加i个连续+1的元素形成子列。这样就不用考虑那么复杂了，不是吗？

· 其他也没什么好说的了，希望跟我一样想要用C解决算法的小伙伴可以从我的代码中能借鉴到有用的地方吧！：D

```
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int** result = (int**)malloc(sizeof(int*) * target);
    int* col = (int*)malloc(sizeof(int) * target);
    int i = 1, m = 0, t = target;
    while (t - i >= 0)
    {
        t -= i++;
    }
    while (t < target && i > 2)
    {
        t += --i;
        if (t % i == 0)
        {
            col[m] = i;
            result[m] = (int*)malloc(sizeof(int) * i);
            for (int k = t / i, j = 0; k < t / i + i; k++, j++)
            {
                result[m][j] = k;
            }
            m++;
        }
    }
    *returnSize = m;
    *returnColumnSizes = col;
    return result;
}
```
