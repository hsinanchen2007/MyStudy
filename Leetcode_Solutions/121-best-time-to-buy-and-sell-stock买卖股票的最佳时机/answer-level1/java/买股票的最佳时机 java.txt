### 解题思路
此处撰写解题思路
求差值
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
    int n = prices.length;
        //设买入的价格
        int buy=0;
        int sold=0;
        int max;
        int cha=0;

        for (int i = 0; i < n-1; i++) {
            buy = prices[i];
            //选最大的利润
            for (int j = i + 1; j < n;j++) {
                max = prices[j]-prices[i];
                if (max>cha){
                    cha=max;
                }


            }



        }


        return cha;
    }
}
```