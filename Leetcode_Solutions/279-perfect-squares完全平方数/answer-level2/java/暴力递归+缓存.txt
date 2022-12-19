### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private Map<Integer, Integer> cache = new HashMap<>();
    public int numSquares(int n) {
        // 取出所有的小于n的完全平方数
        List<Integer> squares = new ArrayList<>();
        for (int i = 1; i < (int)Math.sqrt(n) + 1; i++) {
            squares.add(i * i);
        }
        if (squares.contains(n)) {
            return 1;
        }
        int min = Integer.MAX_VALUE;
        for (Integer square : squares) {
            if (null != cache.get(n - square)) {
                min = Math.min(min, cache.get(n-square) + 1);
            } else {
                min = Math.min(min, numSquares(n-square) + 1);
            }
        }
        cache.put(n, min);
        return min;
    }
}
```