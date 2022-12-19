[@labuladong](/u/labuladong/) 的「[一个方法团灭 6 道股票问题](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-lab/)」写的很好了，但我看完后，总感觉可以思考的再深入一点。

动态规划，我大体上分成这么三板斧。

**第一板斧** —— 找思路，看如何自底部向上。
```
    F[n]的定义
        有些题目需要做一些变形，直接用题目的定义根本推不出来。
        416，413就是一个很好的例子。
    动态规划的公式其实不难推，就那么几种（下面四种）。
    如果这几种套上去都搞不定，那么八成F[n]需要重新定义。

    定义完毕，就要找F[n]和前面n步的关系了，分成四种，挨个套就行，难度由从低到高
    a, F[n]跟前面一两步有关
        这种简单
    b, F[n]跟前面n步都有关
        这种找到公式也不难，但要注意时间优化了，不优化往往就n^2了，举例子《最长上升子序列》
    c, F[n]需要细分
        这种情况下，你发现看着像，但是跟前面n步的关系整的你头疼。
        举个例子，股票的几个中等难度的题就是这样。
        那就把F[n]分成 F1[n] F2[n]
    d, F[n]，一纬数组不够用了
        F[n]的细分其实是这个的简单情况。
        举个例子，股票的状态有出售，买入。那么F[n]再加一纬数组，变成 F[n][]，第二纬只有0，1即可。
        二维比较难的，可以看这道题 分割等和子集

    这道题其实介于c和d之间，即可以用c也可以用d。
    如果直接F(n)去想和之前的关系，反正我是卡在这里了，情况太复杂。。

    要么把问题细分，要么上个二维数组（有些情况下，甚至三维），这个时候公式推起来就快了。
    labuladong是把状态分成了出售和保留
    但事实上，还有的分成了三种状态，也就是题目中描述的三种状态。
        
```
三种状态的参考这个回答：[动态规划求解](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/dong-tai-gui-hua-qiu-jie-by-tangzixia/)

**第二板斧** —— 确认公式
```
    这一步反而基本上没什么难度了
    第一，当前持有股票
        a,昨天如果持有股票，那么今天就保留 hold[n - 1]
        b,前天出售个票，今天买入 unhold[n - 2] - prices[n]
        hold[n]=max(a,b)
    
    第二，当前没有股票
        a，昨天如果持有股票，那么今天就卖出 hold[n - 1] + prices[n]
        b，昨天没有持有股票，今天也没有 unhold[n - 1]
        unhold[n] = max(a,b)
    最后 max(hold[n], unhold[n])
```

**第三板斧** —— 确认需要存储的上1/N步信息是否找对了
```
    这一步有三个作用。
    第一，double check下公式。
    第二，部分情况下，如果只考虑前一步，前两步的话，我们没必要用数组来存储，几个临时变量就OK
了
    第三，边界条件的确认
        这道题的边界条件，是需要n-2，所以在0，1的初始化需要注意
    这三点考虑完，基本上代码很快就写完了
```

不用变量，而用数组存储的代码
只用临时变量的话，这个要怎么写？但我就不贴出来了，代码还是自己写一下比较好。。
好多人抄的代码，看的思路，以为自己懂了，其实有些细节点真的不一定懂。
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 or prices.size() == 1) {
            return 0;
        }
        vector<int> hold(prices.size());
        //需要初始化到2，因为n - 2
        hold[0] = -prices[0];
        hold[1] = max(-prices[0], -prices[1]);
        vector<int> unhold(prices.size());
        //需要初始化到2，因为n - 2
        unhold[0] = 0;
        unhold[1] = max(prices[1] - prices[0], 0);
        if (prices.size() == 2) {
            return max(hold[1], unhold[1]);
        }
        int result = INT_MIN;
        for (int i = 2; i < prices.size(); ++i) {
            //0，1已经赋值了，从2开始
            hold[i] = max(hold[i - 1], unhold[i - 2] - prices[i]);
            unhold[i] = max(hold[i - 1] + prices[i], unhold[i - 1]);
            int cur_max = max(hold[i], unhold[i]);
            if (cur_max > result) {
                result = cur_max;
            }
        }
        return result;
    }
};
```

