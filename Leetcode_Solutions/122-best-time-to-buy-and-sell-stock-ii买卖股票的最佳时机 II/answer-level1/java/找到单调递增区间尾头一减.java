```
public int maxProfit(int[] prices) {
        int day = 0, profit = 0;
        while (day < prices.length) {
            int buy = day;
            while (day + 1 < prices.length && prices[day + 1] > prices[day]) {
                day++;
            }
            profit += prices[day] - prices[buy];
            day++;
        }
        return profit;
    }
```