 public int maxProfit(int[] prices) {
        if(prices.length<2){
            return 0;
        }
        int max =0;
        for(int i=1,j=0;i>=j&&i<prices.length;j=i++){
            if(prices[i]>prices[j]){
                max+=prices[i]-prices[j];
            }
        }
        return max;
    }