# 审题
1. 买卖次数不限制
2. 买前必须全部卖出

# 思路
1. 无思路，直接看题解
2. 贪心算法：买进，高就卖出，重复以上

# 反馈
1. 贪心简洁

# 代码实现
1. 贪心
2. 贪心简洁

## 1.贪心

```java
/**
    * 贪心算法：买进，高就卖出，重复以上
    * 1 ms	42.4 MB
    * @param prices
    * @return
    */
private int greedySolution(int[] prices) {
    int profit = 0;
    for (int i = 1, buy = 0; i < prices.length; i++) {
        if (prices[buy] > prices[i]) {
            buy = i;
        }
        if (prices[i] > prices[buy]) {
            profit += prices[i] - prices[buy];
            buy = i;
        }
    }
    return profit;
}
```

## 2.贪心简洁

```java
/**
    * 贪心算法简洁版
    * 1 ms	42.9 MB
    * @param prices
    * @return
    */
private int greedyCleanSolution(int[] prices) {
    int profit = 0;
    for (int i = 1; i < prices.length; i++) {
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}
```