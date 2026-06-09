递归判断是否到0，或者是否已经访问过



```
class Solution {
    boolean[] visited;

    public boolean canReach(int[] arr, int start) {
        int len = arr.length;
        visited = new boolean[len];
        Arrays.fill(visited, false);

        visited[start] = true;
        return visit(arr, start);
    }

    private boolean visit(int[] arr, int index) {
        if(arr[index] == 0) {
            return true;
        }
        if (index - arr[index] >= 0) {
            if(!visited[index - arr[index]] == true) {
                visited[index - arr[index]] = true;
                if(visit(arr, index - arr[index])) return true;
            }
        }
        if (index + arr[index] <= arr.length - 1) {
            if(!visited[index + arr[index]] == true) {
                visited[index + arr[index]] = true;
                if(visit(arr, index + arr[index])) return true;
            }
        }
        return false;
    }
}
```


