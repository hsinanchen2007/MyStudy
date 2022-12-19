### 解题思路
最近怎么老是碰到回溯
### 代码

```java
class Solution {
    List<List<Integer>> res;
    int n;
    public List<List<Integer>> combine(int n, int k) {
        this.n = n;
        res = new ArrayList<>();
        List<Integer> had = new ArrayList<>();
        dfs(k, had, 1);
        return res;
    }
    void dfs(int k, List<Integer> had, int start) {
        if (k == 0) {
            res.add(new ArrayList(had));
            return;
        }
        for (int i = start; i <= n; i++) {
            had.add(i);
            dfs(k - 1, had, i + 1);
            had.remove((Integer)i);
        }
    }
}
```