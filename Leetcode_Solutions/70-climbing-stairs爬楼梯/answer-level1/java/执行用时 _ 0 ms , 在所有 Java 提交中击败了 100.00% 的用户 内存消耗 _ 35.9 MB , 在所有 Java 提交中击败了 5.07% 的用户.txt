### 解题思路
动态规划思想：第n阶梯的方法次数就会等于第n-1加n-2的次数。但是由于直接动态规划会导致很多重复的计算，所以先将所有的计算值放到map中，再直接取值就好了。

### 代码

```java
class Solution {
    private static HashMap<Integer, Integer> map = new HashMap<Integer, Integer>(){{
        put(1,1);
        put(2,2);
    }};
    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        map.put(n - 1, climbStairs(n-1));
        return map.get(n - 1) + map.get(n - 2);
    }
}
```