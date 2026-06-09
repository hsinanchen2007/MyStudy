### 解题思路
思路很简单：遍历一次数组，每次把p[i]的值和当前的最小值作比较，p[i]大的话计算差值，更新最大利润，p[i]小的话就更新当前最小值。ok，跑一下
执行用时 :16 ms, 在所有 C 提交中击败了43.41%的用户
内存消耗 :8.1 MB, 在所有 C 提交中击败了10.75%的用户
。。。。。。
你们都是什么魔鬼啊
### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int ans=0;
    int cur_min=INT_MAX;

    for(int i=0;i<pricesSize;i++)
    {
        if(prices[i]>cur_min)
        {
            int t=prices[i]-cur_min;
            ans=ans>t?ans:t;
        }
        else if(prices[i]<cur_min)
        {
            cur_min=prices[i];
        }
    }
    return ans;
}
```