### 解题思路
DFS

### 代码

```java
class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> results = new ArrayList<>();
        dfs(n, new ArrayList<>(), results);

        return results;
    }

    //subsets里面存的是列值
    private void dfs(int n, List<Integer> subsets, List<List<String>> results) {
        if (subsets.size() == n) {
            results.add(paintBoard(n, subsets));
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!isValid(i, subsets)) {
                continue;
            }

            subsets.add(i);
            dfs(n, subsets, results);
            subsets.remove(subsets.size() - 1);
        }
    }

    private List<String> paintBoard(int n, List<Integer> subsets) {
        List<String> results = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int col = subsets.get(i);
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < n; j++) {
                if(j == col) {
                    sb.append('Q');
                } else {
                    sb.append('.');
                }
            }
            results.add(sb.toString());
        }
        return results;
    }

    private boolean isValid(int col, List<Integer> subsets) {
        int row = subsets.size();
        for (int i = 0; i < subsets.size(); i++) {
            if (col == subsets.get(i)) {
                return false;
            }

            if (row - col == i - subsets.get(i) || row + col == i + subsets.get(i)) {
                return false;
            }
        }
        return true;
    }
}
```