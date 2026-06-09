### 解题思路
1.需要找出数组中差值最大的两个数i,j  2.j需要大于i

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
 int maxPrice = 0;
        for (int i=0;i<prices.length;i++){
            for (int j=i ; j< prices.length;j++){
                maxPrice = Math.max(maxPrice,prices[j] - prices[i]);
            }
        }
        return maxPrice;
    }
}
```
时间复杂度：O(n^2)
空间复杂度：O(1)