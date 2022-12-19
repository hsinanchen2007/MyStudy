### 解题思路
这里由于要使用贪心所以不敢保证数据都是有序的
先用快排把数据排序一下保证数据的有序性

这里用都是dfs ➕ 剪枝
最重要都是这里
n + i < min
你都代码能不能在规定都时间内完成靠的就是这一步剪枝
现在来分析一下为什么这里要这样写
其原因是当min不再是99999999的时候已经有一个解啦，但是这个解不一定是最优的
但是如果你当前这个解都大于min的话说明你肯定不是最优解，就直接放弃就好啦return掉
还有的同学说那我把i减小啊，这样n + i 就比min小啦
但是这里我们的dfs 是用的贪心思想
i = amount / coins[len] 这里得到都是最优得数量
你在这一步都已经不满足最优啦，之后取出来的硬币数一定是多的
所有我们要在这里果断的return掉避免做一些没意义的递归
还有一个减少时间点的地方
如果你是这样写
 for(int i = num; i > -1; i--)
    if(n + i > min)
        return;
那么你的时间消耗会比
for(int i = num; i > -1 && n + i < min; i--)这样写多上4ms

刚开始我也没写出来 主要是想dfs会超时，就看了下大家的题解，然后发现dfs可以做出来就花了些时间想了下怎么做
还有一种做法是dp 动态规划
建议还是也学一下，都要会一些嘛
大家加油哦

最后这个代码跑的时间是4ms 内存 12.5MB

### 代码

```cpp
class Solution {
public:
    int min = 99999999;

    int coinChange(vector<int>& coins, int amount) {

        int len = coins.size() - 1;
        sort(coins, 0, len);

        dfs(coins, len, amount, 0);
        
        return min == 99999999 ? -1 : min;
    }

    void dfs(vector<int>& coins, int len, int amount, int n)
    {
        if(amount == 0)
        {
            min = min > n ? n : min;
            return ;
        }

        if(len == -1)
            return ;
        
        int num = amount / coins[len];
        
        for(int i = num; i > -1 && n + i < min; i--)
            dfs(coins, len - 1, amount - (i * coins[len]), n + i);
    }

    void sort(vector<int>& coins, int left, int right)
    {
        if(left >= right)
            return ;
        int i = left, j = left, temp;

        for(;i < right; i++)
            if(coins[i] <= coins[right])
            {
                temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
                j++;
            }
        temp = coins[j];
        coins[j] = coins[right];
        coins[right] = temp;

        sort(coins, left, j - 1);
        sort(coins, j + 1, right);
    }
};
```