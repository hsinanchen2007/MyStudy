    public int maxProfit(int[] prices) {
        int profit = 0;
        boolean isUp = false;
        int i=0, j=1;
        for(j=1 ; j<prices.length; j++){
            if(prices[j] > prices[j-1]){
                if(!isUp){
                    i = j-1;
                }
                isUp = true;
            } else {
                if(isUp){
                    profit += prices[j-1] - prices[i];
                }
                isUp = false;
            }
        }
        if(isUp){
            profit += prices[j-1] - prices[i];
        }
        return profit;
    }
