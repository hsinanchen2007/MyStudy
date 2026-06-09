### 解题思路
1. 统计每个位置的筹码数量
2. 从奇数位置移动到奇数位置不需要消耗
3. 从偶数位置移动到偶数位置不需要消耗
4. 最后比较奇数堆和偶数堆的数量，返回小的那一方。

### 代码

```java
class Solution {
    public int minCostToMoveChips(int[] chips) {
        Map<Integer,Integer> map = new HashMap<>();
        for (int chip : chips) {
            if (map.containsKey(chip))
                map.put(chip,map.get(chip) + 1);
            else
                map.put(chip,1);
        }
        if (map.size() == 0 || map.size() == 1)
            return 0;
        int left = 0;
        int right = 0;
        for (Integer integer : map.keySet()) {
            if (integer % 2 == 0)
                right += map.get(integer);
            else 
                left += map.get(integer);
        }
        return Math.min(left, right);
    }
}
```