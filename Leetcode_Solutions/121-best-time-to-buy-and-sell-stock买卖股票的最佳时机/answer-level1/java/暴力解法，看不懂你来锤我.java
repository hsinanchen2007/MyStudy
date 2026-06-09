class Solution {
    public int maxProfit(int[] prices) {
        int res = 0;
        int temp = 0;
        for(int i=0;i<prices.length;i++){
            for(int j = i+1;j<prices.length;j++){
                if(prices[j] > prices[i]){
                    temp = prices[j] - prices[i];
                }
                if( temp > res){
                    res = temp;
                }
            }
        }
        return res;
    }
}