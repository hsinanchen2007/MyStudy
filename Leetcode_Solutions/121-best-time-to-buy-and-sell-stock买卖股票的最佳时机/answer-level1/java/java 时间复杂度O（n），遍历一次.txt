 java 时间复杂度O（n），遍历一次 维护两个值，一个是最小值；一个是利润最大值； 从前往后遍历，如果遇到更小的值，就更新最小值，并且 实时计算利润最大值 并更新
```
    /**
     * 121 股票的最大利润
     * @param prices
     * @return
     */
    public int maxProfit(int[] prices) {
        int len = prices.length;
        if (len <= 1) {
            return 0;
        }
        int res = 0;
        int min = prices[0];
        for (int i = 1; i < len; i++) {
            if (prices[i] < min) {
                min = prices[i];
            }
            res = Math.max(res, prices[i] - min);
        }
        return res;
    }
```
