### 解题思路
参考的别人的回答，对数组进行排序，最后一个石头变成最后一个-倒数第二个，倒数第二个归0，再排序。

### 代码

```java
class Solution {
    public int lastStoneWeight(int[] stones) {
        // 对石头进行递增排序
        Arrays.sort(stones);
        // 最后一个石头的索引
        int lastOne = stones.length - 1;
        // 一共进行石头总数的次数比较
        for (int cnt = 1; cnt <= lastOne; cnt++) {
            // 最后一个石头即最大的石头，变为最大的-次大的之后的结果
            stones[lastOne] = stones[lastOne] - stones[lastOne - 1];
            // 次大的归为0
            stones[lastOne - 1] = 0;
            // 再重新排序
            Arrays.sort(stones);
        }
        return stones[lastOne];
    }
}
```