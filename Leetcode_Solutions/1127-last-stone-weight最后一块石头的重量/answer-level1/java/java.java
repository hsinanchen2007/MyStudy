### 解题思路

### 代码

```java
class Solution {
    public int lastStoneWeight(int[] stones) {
        // 一个石头 直接返回
        if (stones.length == 1) {
            return stones[0];
        }
        // 从最后一个石头开始
        for (int i = stones.length - 1; i > 0; --i) {
            // 排序0 到最后一个石头
            Arrays.sort(stones, 0, i + 1);
            // 将粉碎剩余放入靠前的石块
            stones[i - 1] = stones[i] - stones[i - 1];
            if (stones[i - 1] == 0) {
                // 如果没有剩余 缩小一个单位
                --i;
            }
            
        }
        
        return stones[0];
        
    }
}
```