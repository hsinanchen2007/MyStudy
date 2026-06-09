### 解题思路
用current保存当前较小的值，并与数组中的下一个值做差，看得到的是不是差是不是最大的。

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices==null||prices.length==0)
        return 0;
        int greatest = 0;
        int current = prices[0];
        for(int i=1;i<prices.length;i++)
        {
            current=Math.min(current,prices[i]);
            greatest=Math.max(greatest,prices[i]-current);
        }
        return greatest;
    }
}
```
### 复杂度分析：
- 时间复杂度：O(n),只遍历了一次数组。
- 空间复杂度：O(1),没有开辟新的空间。