public class Solution {
    public int MaxProfit(int[] prices) {
        if(prices==null||prices.Length==0) return 0;
        int minHis=prices[0];
        int maxPro=0;
        for(int i=0;i<prices.Length;i++)
        {
            maxPro=Math.Max(maxPro,prices[i]-minHis);
            minHis=Math.Min(minHis,prices[i]);
        }
        return maxPro;
    }
}