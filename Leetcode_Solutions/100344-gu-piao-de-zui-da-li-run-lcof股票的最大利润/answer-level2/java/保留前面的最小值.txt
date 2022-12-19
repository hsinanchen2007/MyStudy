### 解题思路
迭代比较最小值，小于则更新最小值，大于等于则求差值，
并迭代更新最大差值

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int curmin = Integer.MAX_VALUE;
        int res = 0;
        for (int i=0;i<prices.length;i++) {
            if (prices[i]<curmin) {
                curmin = prices[i];
            } else {
                int diff = prices[i] - curmin;
                res = Math.max(res, diff);
            }
        }
        return res;
    }
}
```
![image.png](https://pic.leetcode-cn.com/42d448b560d3aad3370d65cda7803fd16987bd95c55699ba0bf346e8e6eb5b48-image.png)
