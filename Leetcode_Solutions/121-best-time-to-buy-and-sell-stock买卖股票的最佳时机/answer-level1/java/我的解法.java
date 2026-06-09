  public int maxProfit(int[] prices) {
        int minValue=Integer.MAX_VALUE;
        int complement=0;
        for(int price:prices){
            minValue=Math.min(minValue,price);
            complement=Math.max(complement,price-minValue);
        }
        return Math.max(complement,0);
    }