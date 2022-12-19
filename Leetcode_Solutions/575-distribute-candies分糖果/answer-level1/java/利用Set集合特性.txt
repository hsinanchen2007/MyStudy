### 解题思路

### 代码

```java
class Solution {
    public int distributeCandies(int[] candies) {
        // 可拥有的最多糖果
        int countMax = candies.length / 2;
        // 存放类型
        Set<Integer> type = new HashSet<Integer>();
        
        for (int i = 0; i < candies.length; ++i) {
            type.add(candies[i]);
            if (type.size() == countMax) {
                break;
            }
        }
        
        return type.size();
    }
}
```