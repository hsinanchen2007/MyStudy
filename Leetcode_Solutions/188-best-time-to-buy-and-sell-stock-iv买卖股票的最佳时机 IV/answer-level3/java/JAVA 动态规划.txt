
有了之前k=2的解题经验，很容易就可以写出直接的代码
通过了样例之后以为搞定直接提交，结果出现了k=10E的测试用例
知道要从dp数组开始下手简化，但是由于交易次数不确定性，一直没想到简化的手段
学习了其他人分析后得知，当k的次数比实际可以完成的所有次数都大的时候，可以当做没有限制来解题
而没有次数限制的股票购买问题之前已经解过了。
从买卖动作必须成对很容易就想出当k>len/2的时候，k == ∞

```
class Solution {
    public int maxProfit(int k, int[] prices) {
        int len = prices.length;
        if(len == 0) return 0;
        if(k<1) return 0;

        int[] dp;
        int trans;     
        
        //当k>len/2的时候，表示在当前时间点内可以完成的实际最大交易次数不会大于k，此时可以当做两种状态的交易来解;
        if(k>len/2) {
            dp = new int[2];
            dp[0]=0;
            dp[1]=-prices[0];
            trans = 2;
            for(int i=0; i<len; i++){
                dp[0] = Math.max(dp[0],dp[1]+prices[i]);
                dp[1] = Math.max(dp[1],dp[0]-prices[i]);
            }
            return Math.max(dp[0],dp[1]);
        }else{
            dp = new int[2*k+1];
            dp[0]=0;
            dp[1]=-prices[0];
            trans=2*k+1;
            for(int i=3; i<trans; i=i+2){
                dp[i] = Integer.MIN_VALUE;
            }

            for(int i=0; i<len; i++){
                for(int j=1; j<trans; j++){
                    if(j%2==0){
                        dp[j] = Math.max(dp[j],dp[j-1]+prices[i]);
                    }else{
                        dp[j] = Math.max(dp[j],dp[j-1]-prices[i]);
                    }
                }
            }
            int max=0;
            for(int j=1; j<trans; j++){
                if(dp[j]>max){
                    max = dp[j];
                }
            }
            return max;
        }

       
    }
}
```
