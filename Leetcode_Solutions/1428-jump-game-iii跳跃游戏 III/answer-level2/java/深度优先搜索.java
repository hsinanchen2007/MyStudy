```
class Solution {
    boolean[] visited;

    public boolean canReach(int[] arr, int start) {
        visited = new boolean[arr.length];
        return dfs(arr, start);
    }

    boolean dfs(int[] arr, int index) {
        if (visited[index]) {
            return false;
        }
        if (arr[index] == 0) {
            return true;
        }
        visited[index] = true;

        if (index - arr[index] >= 0) {
            if (dfs(arr, index - arr[index])) {
                return true;
            }
        }
        if (index + arr[index] < arr.length) {
            if (dfs(arr, index + arr[index])) {
                return true;
            }
        }

        visited[index] = false;

        return false;
    }
}
```

