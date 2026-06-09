### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private int n;
    private int k;
    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> combinationSum3(int k, int n) {
        if (k == 0 || n == 0) return res;
        this.n = n;
        this.k = k;
        dfs(0, 0, 0, new ArrayList<Integer>());
        return res;
    }

    private void dfs(int index, int sum, int num, List<Integer> now) {
        if (sum == n) {
            if (num == k) res.add(new ArrayList(now));
            return ;
        }
        int t = 9 - (k - num) + 1;
        for (int i = index + 1; i <= t; i++) {
            if (sum + i <= n && num < k) {
                now.add(i);
                dfs(i, sum + i, num + 1, now);
                now.remove(now.size() - 1);
            }
        }
    }
}
```