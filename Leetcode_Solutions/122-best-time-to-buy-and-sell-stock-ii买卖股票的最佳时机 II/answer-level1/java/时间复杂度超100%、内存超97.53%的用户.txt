![image.png](https://pic.leetcode-cn.com/3b42ba2baccb20431db5a3e1365930587d83363699b16eb9e2e4a04ef6521118-image.png)
```
class Solution {
        public int maxProfit(int[] prices) {
            if (prices==null||prices.length==0)
                return 0;
            int pre=prices[0],res=0;
            for (int i = 1; i <prices.length ; i++) {

                if (prices[i]-pre>0){
                    res+=prices[i]-pre;
                    pre = prices[i];
                }else pre=prices[i];
            }
            return res;
        }
    }
```
只要找到一个数比之前的值大，就卖出一次。