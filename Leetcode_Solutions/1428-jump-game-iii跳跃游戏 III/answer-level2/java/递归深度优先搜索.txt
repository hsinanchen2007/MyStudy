递归深度优先搜索
```
class Solution {
    public boolean canReach(int[] arr, int start) {
        return dfs(start, arr, new boolean[arr.length]);
    }

    private boolean dfs(int start, int[] arr, boolean[] visited) {
        if (start < 0 || start >= arr.length || visited[start]) {
            return false;
        }

        if (arr[start] == 0) {
            return true;
        }
        visited[start] = true;

        return dfs(start + arr[start], arr, visited) || dfs(start - arr[start], arr, visited);
    }
}
```
