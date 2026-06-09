    public int maxProfit(int[] prices) {
        int slow = 0;
        int fast = 0;
        int total = 0;
        int length = prices.length;
        while (fast < length && slow < length) {
            if (prices[fast] > prices[slow]) {
                total += prices[fast] - prices[slow];
                slow = fast;
            } else if (prices[fast] < prices[slow]) {
                slow++;
            } else {
                fast++;
            }
        }
        return total;
    }