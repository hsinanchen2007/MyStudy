![image.png](https://pic.leetcode-cn.com/3806d0983ed6ef695a1e0b3dea8c758e3135b92875e1ef6349779b90dcd1b1ca-image.png)

### 解题思路
高赞答案大都是各种秀出天际的动态规划，以及据说过不了的贪心，我都没有看懂代码，可能是着急刷题没耐心好好看，所以自己想了个比较自然的思路。

有一个题解中说的一句话深得我心，说这题可以拆成两个简单版本的题目。围绕这一点，我想出了自己的解法。
那就看看怎么个拆法吧。

最开始的构想中，是选出收益最大的一次交易，在这次交易的买入之前和卖出之后，分别进行一次搜索，再找到收益次大的另一次交易，两者收益相加就是答案。
听起来好像没有什么问题，写码也很简单，交上去之后过了70%的测例。

为什么只过了70%呢？因为有一点小纰漏，少考虑了如下这种情况
![image.png](https://pic.leetcode-cn.com/37d9dae6ed8d6a78d49cc6117e285567658d6e4443769a12ea9e97d6e8edacbb-image.png)

来概括一下这种情况，我们已经找到了最大收益的一次交易买入和卖出时间，以及买入前和卖出后的收益次大交易，在什么情况下答案会错误呢？
在收益最大的交易期间，如果股票出现了一次下跌，跌幅大于次大收益，那么将最大收益交易在股票下跌前卖出，下跌后买入，拆成两次交易，收益就会更大。
大概就是这样吧
![捕获.JPG](https://pic.leetcode-cn.com/e80ef8e22fc125fed6759c4bf5e408b4790820f40a193029e48f8f0bd2e3f054-%E6%8D%95%E8%8E%B7.JPG)

补充完这种情况后，这题就过了。实际上就是至多三次正向贪心和一次反向贪心。接下来也要研究一下大佬们的动态规划算法了。

在我的代码中有min_loc, max_loc，分别指受益最大的交易买入和卖出时间，cheap_loc指的是最便宜的股价的时间，注意，只有当max_loc更新时才能更新min_loc,这也是当初疏忽的一个地方。

### 代码

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (!len || len == 1)
            return 0;
        int cheap_loc = 0, min_loc = 0, max_loc = 0, cheap = prices[0], profit = 0;
        for (int i = 1; i < len; i++) {
            if (prices[i] < cheap) {
                cheap = prices[i];
                cheap_loc = i;
            }
            else if (prices[i] - cheap > profit) {
                profit = prices[i] - cheap;
                max_loc = i;
                min_loc = cheap_loc;
            }
        }//找出收益最大的一次交易
        int ans = 0;
        cheap = prices[0];
        if (min_loc == len - 1) 
            return profit;
        for (int i = 1; i < min_loc; i++) {
            if (prices[i] < cheap) {
                cheap = prices[i];
            }
            else if (prices[i] - cheap > ans) {
                ans = prices[i] - cheap;
            }
        }//收益最大交易买入前的最大收益
        cheap = prices[min_loc + 1];
        for (int i = min_loc + 2; i < max_loc; i++) {
            if (prices[i] > cheap) {
                cheap = prices[i];
            }
            else if (ans < cheap - prices[i]) {
                ans = cheap - prices[i];
            }
        }//是否会出现跌幅更大的情况
        if (max_loc == len - 1) 
            return ans + profit;
        cheap = prices[max_loc + 1];
        for (int i = max_loc + 2; i < len; i++) {
            if (prices[i] < cheap) {
                cheap = prices[i];
            }
            else if (prices[i] - cheap > ans) {
                ans = prices[i] - cheap;
            }
        }//最大收益交易卖出后的最大收益
        return ans + profit;        
    }
};
```