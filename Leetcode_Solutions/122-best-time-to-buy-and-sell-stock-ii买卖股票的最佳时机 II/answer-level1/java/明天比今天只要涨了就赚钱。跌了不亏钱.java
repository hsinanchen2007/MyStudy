class Solution {
    public int maxProfit(int[] prices) {
        int money=0;
        for(int i=0;i<prices.length-1;i++){
            if(prices[i+1]-prices[i]>0){
                money=money+prices[i+1]-prices[i];
            }
        }
     return money;       
    }
}