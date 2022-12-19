### 解题思路
思路非常简单，不信你看
！

### 代码

```java
class Solution {
    public int climbStairs(int n) {
		HashMap<Integer, Integer> map = new HashMap<>();
		map.put(1,1); map.put(2, 2);
		for (int i=3; i<100; ++i) map.put(i, map.get(i-1)+map.get(i-2));
		return map.get(n);
    }
}
```