class Solution {
    public int maxProfit(int[] prices) {
           int sum = 0;
        int down = 0;
        for (int i = 1; i < prices.length; i++) {

            if (prices[i] > prices[down]) {
                sum += prices[i] - prices[down];
            }
             down=i;

        }

        return sum;
    }
}


是不是有点猛