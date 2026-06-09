### 解题思路
回溯算法 java解法

### 代码

```java
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            if (i > n - k + 1) {
                break;
            }
            dfs(res, null, i, n, k - 1);
        }
        return res;
    }

    private void dfs(List<List<Integer>> res, List<Integer> child, int nowNum, int n, int k) {
        if (child == null) {
            child = new LinkedList<>();
        }
        child.add(nowNum);
        if (n - nowNum < k) {
            return;
        }
        if (k == 0 && !res.contains(child)) {
            res.add(child);
            return;
        }
        for (int i = 1; i < n; i++) {
            dfs(res, new LinkedList<>(child), nowNum + i, n, k - 1);
        }
    }
}
```