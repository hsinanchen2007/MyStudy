我首先想到峰谷法，自己写的程序有一点啰嗦，参考官方题解第二种方法峰谷法。官方参考方法实际运行发现一个问题，那就是会出现在初始化峰值和谷值时候会出现数组越界，经过优化正确版本如下（新手小白，如有错误，请各位大佬赐教）
class Solution {
    public int maxProfit(int[] prices) {
        int i = 0;
        int min = Integer.MAX_VALUE;
        int max = 0;
        int maxprofit = 0;
        while (i < prices.length - 1) {
            while (i < prices.length - 1 && prices[i] >= prices[i + 1])
                i++;
            min = prices[i];
            while (i < prices.length - 1 && prices[i] <= prices[i + 1])
                i++;
            max = prices[i];
            maxprofit += max - min;
        }
        return maxprofit;
    }

}
实测运行时间1ms,内存消耗37.1MB
