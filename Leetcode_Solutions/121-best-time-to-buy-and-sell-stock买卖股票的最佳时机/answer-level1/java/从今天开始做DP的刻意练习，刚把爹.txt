### 解题思路
![QQ截图20200309203925.png](https://pic.leetcode-cn.com/01f5cd314891f8bc6740d986289b2850319c0671f8882b683f0163c3c4fb8bf6-QQ%E6%88%AA%E5%9B%BE20200309203925.png)

没少好说的，m(i)=max{m(i-1),第i天的价格-前i-1天的最小价格}
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
          if(prices.length<2){
            return 0;
        }
        /**递归方程：
         * m(i)：前i天所能获得的最大利润
         m(i)=max{m(i-1),第i天的价格-前i-1天的最小价格}.....一维的，备忘录m是一维数组
         * */
        int min_price_day=prices[0];
        int [] m=new int[prices.length];
        m[0]=0;//前1天买彩票必是0
        for(int i=1;i<prices.length;i++){
            if(prices[i]<min_price_day){
                min_price_day=prices[i];
            }
            if(prices[i]-min_price_day>m[i-1]){
                m[i]=prices[i]-min_price_day;
            }else{
                m[i]=m[i-1];
            }

        }

        return m[m.length-1];

    }
}
```