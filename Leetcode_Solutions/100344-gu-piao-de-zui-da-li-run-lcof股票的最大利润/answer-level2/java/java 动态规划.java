这是leetcode`53连续子数组最大和`的变形：
1. `dp[i]`代表某一段时间的累计收益
2. 如果大于0，那么就添加当前收益。当前收益大于0当然最好，稍微为负也没什么关系，总收益还是正的。（如果当前收益太负，总收益兜不住底了，在循环检查中，有第3条兜住）
3. 如果小于0，那么就重新开始计算

```java []
public int maxProfit(int[] prices) {
        
        //1、判断
        if(prices.length < 2){
            return 0;
        }

        //2、构建dp数组
        int[] dp = new int[prices.length];
        dp[0] = 0;  //也可以定义为 (0-prices[0])

        int profit = Integer.MIN_VALUE;

        //3、循环计算dp
        for(int i=1; i<prices.length; i++){
            if(dp[i-1] > 0){
                dp[i] = dp[i-1] + (prices[i]-prices[i-1]);
            }else{
                dp[i] = (prices[i]-prices[i-1])>0 ? (prices[i]-prices[i-1]) : 0;
            }

            profit = Math.max(profit, dp[i]);
        }

        return profit;
    }
```
