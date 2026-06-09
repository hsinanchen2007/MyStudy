```Java
public int maxProfit(int[] prices) {
    // 最大收益
    int res = 0;
    // 最小买入金额
    int min = Integer.MAX_VALUE;
    // 不断更新 最大收益 和 最小买入金额
    for (int price: prices) {
        min = Math.min(price, min);
        res = Math.max(res, price - min);
    }
    return res;
}
```
