1.记f(i)为当前元素右边所有元素的最大值(即卖出价格)，即维护了一个相对于i的最佳卖出价格的一维数组。
2.如何获取f(i)？状态转移方程:f(i) = max{f(i+1),prices[i+1]}
3.设定初始值f(n-1)=-65535,(取一个较小值即可)，从尾部开始遍历，以填充f(i);
4.获得数组f后，再从头遍历prices数组，计算当前价格prices[i]和最佳卖出价格f[i]的差值即为本次利润，在遍历过程中取最大利润即可。

```
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length==0){
            return 0;
        }
        int maxProfit = 0;
        //记f(i)为右边价格的最大值(卖出价格)
        int[] f = new int[prices.length];
        f[prices.length-1] = -65535;
        for(int i=prices.length-2;i>=0;i--){
            f[i] = Math.max(f[i+1],prices[i+1]);
        }
        for(int i=0;i<prices.length-1;i++){
            if(f[i]-prices[i]>maxProfit){
                maxProfit = f[i]-prices[i];
            }
        }
        return maxProfit;
    }
}
```
