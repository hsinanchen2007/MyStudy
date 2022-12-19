题目121中只操作一次，题目很简单，这道题目最多操作两次，我就想这两者应该有某种瓜葛。
思路如下：先求出只操作一次的最大利润以及买入与卖出节点记为（start, end），如果有第二次操作，则分两种情况：
  1. 两次操作都在(start, end)之间，那么中间必定会有一段亏损时间段，使得一次操作获利较少，我们只需求出中间亏损最大的那一段即可将则一段分为两次操作且获利最大
  2. 还有一次操作在（start, end)之外，这更好办了，我们只要求出前后两个时间段的最大获利操作时间节点就行

之后就取最大的获利操作便是答案了。时间复杂度为O(n)，两次遍历只花了4ms。

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) return 0;
        //首先计算全局最大利润的买卖时间节点，这和题目121是一致的
        vector<int> tmp = maxPro(prices, 0, len);
        //tmp记录买入节点和卖出节点
        int minProfit = 0;
        int cost = prices[tmp[0]];
        //计算在买入节点与卖出节点之间亏的最多的一段minProfit，只需将之前的代码改变不等号方向即可
        for (int i = tmp[0]; i <= tmp[1]; i++) {
            if (prices[i] < cost && (prices[i] - cost) < minProfit) {
                minProfit = prices[i] - cost;
            }   
            else if (prices[i] >= cost){
                cost = prices[i];
            }
        }
        //分别计算前后两段时间的最大收益
        int anotherMax = max(maxPro(prices, 0, tmp[0])[2], 
                             maxPro(prices, tmp[1] + 1, prices.size())[2]);
        // cout<<anotherMax<<-minProfit<<maxProfit<<endl;
        return (tmp[2] + max(anotherMax, -minProfit));
        
    }
    
    vector<int> maxPro(vector<int> & prices, int start, int end) {
        // cout<<start<<", "<<end<<endl;
        int maxProfit = 0;
        vector<int> res {start, start, 0};
        if (start >= end) return res;
        int cost = prices[start];
        int curStart = 0;
        for (int i = start; i < end; i++) {
            int p = prices[i] - cost;
            if (p > 0 && p > maxProfit) {
                maxProfit = p;
                res[1] = i; 
                res[0] = curStart;
            }   
            else if (p <= 0){
                cost = prices[i];
                curStart = i;
            }
        }
        res[2] = maxProfit;
        // cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;
        return res;
    }
};
```
