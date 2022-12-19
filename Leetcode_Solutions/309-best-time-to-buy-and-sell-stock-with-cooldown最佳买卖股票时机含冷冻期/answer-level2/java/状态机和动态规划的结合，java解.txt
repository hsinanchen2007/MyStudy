```java
class Solution {
    public int maxProfit(int[] prices) {
            // 这道题与其他动态规划最不同的就是它的情况较为复杂，需要有状态机来记录，分三种状态
            // 状态机之间的转换是 卖 上一个状态 肯定是买 ；买 上一个状态 肯定是冷冻期 ；冷冻期 上一个状态 肯定是 卖 
        
            // 而且还有极为重要的一点是，什么都不做 不是 真的什么都不做，是因为冷冻期而什么都不做，
            // 对于程序来说，只要手里没有股票，并且不是冷冻期，就一定会买，不存在手里没有，看见贵的就不买的情况
            // 今天要做的事是考虑今天 是 买、卖、还是因为冷冻期所以什么都不做
        if (prices.length == 0) return 0;
            // 第一天要是买的话就是负的,卖的话 
        int buy = -prices[0], sell = 0, nothingToDo = 0, presell = 0;
        for (int i : prices) {
            presell = sell; // 三个状态相互转化，需要有一个临时变量来记录
            sell = Math.max(buy + i, sell); // 卖 上一个状态 肯定是买 
            buy = Math.max(nothingToDo - i, buy); // 买 上一个状态 肯定是冷冻期
            nothingToDo = Math.max(presell, nothingToDo); // 冷冻期 上一个状态 肯定是 卖 
        }
        return sell;
    }
}
```