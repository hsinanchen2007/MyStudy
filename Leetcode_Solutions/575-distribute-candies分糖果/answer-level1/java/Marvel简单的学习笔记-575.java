### 解题思路
利用set的自动去重，将candies[]中所有元素添加进set，便可得到种类数，糖果种类数和糖果总数一半这两者的较小者便是答案。
时间复杂度：O(n)。遍历数组添加进set。
空间复杂度：O(n)。当每个糖果种类均不同时，空间复杂度达到最大。

### 代码

```java
class Solution {
    public int distributeCandies(int[] candies) {
        Set<Integer> set = new HashSet<Integer>();
        for(int i : candies)
            set.add(i);
        return Math.min(candies.length/2, set.size());
    }
}
```