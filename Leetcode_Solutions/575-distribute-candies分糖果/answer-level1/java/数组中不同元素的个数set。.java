### 解题思路
此处撰写解题思路
1.用hashset求出数组中不同元素的个数。
2.然后取set元素个数与candies.length / 2的最小值
**不同--应该想到HashSet**;**集合去重**

### 代码

```java
class Solution {
    public int distributeCandies(int[] candies) {
        HashSet<Integer> differentCandis=new HashSet<>();
        for (int candy : candies) differentCandis.add(candy);
        return Math.min(differentCandis.size(), candies.length / 2);
    }
}
```