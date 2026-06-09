### 代码

```java
class Solution {
    public Map<Integer, Integer> map = new HashMap<>();

    public int cuttingRope(int n) {
        map.put(2, 1);
        return dfs(n);
    }

    private int dfs(int n) {
        if (map.containsKey(n)) {
            return map.get(n);
        }
        int res = 0;
        for (int i = 1; i <= (n + 1) / 2; i++) {
            res = Math.max(res, Math.max(i * (n - i), i * dfs(n - i)));
        }
        map.put(n, res);
        return res;
    }
}
```