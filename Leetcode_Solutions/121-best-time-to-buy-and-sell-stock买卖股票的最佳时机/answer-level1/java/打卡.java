    // min记录i之前股票最小值
    // max记录到当前位置时收益的最大值
    class Solution {
        public int maxProfit(int[] prices) {
            if(prices.length <= 1) {
                return 0;
            }
            int min = prices[0];
            int max = 0;
            for(int i = 1;i < prices.length;i++) {
                max = Math.max(max, prices[i] - min);
                min = Math.min(min, prices[i]);
            }
            return max;
        }
    }