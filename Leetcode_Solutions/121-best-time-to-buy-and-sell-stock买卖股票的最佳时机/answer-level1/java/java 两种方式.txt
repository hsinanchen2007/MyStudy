### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    //暴力,两次遍历
    public int maxProfit(int[] prices) {
        int result=0;
        for(int i=0;i<=prices.length-2;i++){
            for(int j=i+1;j<=prices.length-1;j++){
                //判断当前值 prices[i] ,小于prices[i]之后的值,只要小于就保存结果,一直取结果的最大值
                if(prices[i]<prices[j]){
                    result=Math.max(result,prices[j]-prices[i]);
                }
            }
        }
        return result;
    }
```
```java
    //一次遍历
    public int maxProfit(int[] prices) {
        //保留最小值
        int minPrices=Integer.MAX_VALUE;
        //结果
        int result=0;
        for(int i=0;i<prices.length;i++){
            //判断是否比最小值小,如果比最小值小,保存该值
            if(prices[i]<minPrices){
               minPrices= prices[i];
            }else{
                //如果比最小值大,计算出相差值,与result进行比较,保存大的
                result=Math.max(result,prices[i]-minPrices);
            }
            
        }
        return result;
    }
}
```