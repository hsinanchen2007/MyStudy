```java []
class Solution {
    public int maxProfit(int[] prices) {
        int min = Integer.MAX_VALUE, max = 0, ans = 0;


        for(int price : prices) {
            if(min > price) {
                min = price;
                max = 0;
            } else {
                max = Math.max(max, price);
                ans = Math.max(ans, max - min);
            }
        }

        return ans;
    }
}
```
```python3 []

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0 : return 0
        min, ans = prices[0], 0

        for price in prices :
            if min > price : min = price
            else : ans = max(ans, price - min)

        return ans
```

