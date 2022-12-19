### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private int n;
    private int k;
    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> combine(int n, int k) {
        if (n == 0 || k == 0) return res;
        this.k = k;
        this.n = n;
        dfs(0, new ArrayList<Integer>());
        return res;
    }
    private void dfs(int index, List<Integer> now) {
        //if (index == n && now.size() < k) return ;
        if (now.size() == k) {
            res.add(new ArrayList(now));
            return ;
        }
        int t = n - (k - now.size()) + 1;
        for (int i = index + 1; i <= t; i++) {
            now.add(i);
            dfs(i, now);
            now.remove(now.size() - 1);
        }
    }
}
```