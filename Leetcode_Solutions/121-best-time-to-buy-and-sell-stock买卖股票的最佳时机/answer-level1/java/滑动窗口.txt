### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int max=0;
        int n=prices.length;
        if(n==0)return 0;
        int left=0;
        int right=0;
        while(right<n){
            
            if(prices[right]<prices[left]){
                left=right;
            }
            max=Math.max(max,prices[right]-prices[left]);
            right++;
        }
    return max;
   }
}
```