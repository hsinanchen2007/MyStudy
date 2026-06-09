


### 代码

```java
class Solution {
    public int factorial(int n) {
        int result = 1;
        for (int i = 1; i <= n; ++i) {
            result *= i;
        }
        return result;
    }

    public void count(boolean[] visited, StringBuilder sb, int index, int k) {
        if (index >= visited.length) {
            return;
        }
        int remain = visited.length - 1 - index;
        for (int i = 1; i < visited.length; ++i) {
            if (!visited[i]) {
                int tmp = k - factorial(remain);
                if (tmp > 0) {
                    k = tmp;
                } else {
                    visited[i] = true;
                    sb.append(i);
                    count(visited, sb, index + 1, k);
                }
            }
        }
    }

    public String getPermutation(int n, int k) {
        boolean[] visited = new boolean[n + 1];
        StringBuilder sb = new StringBuilder();
        count(visited, sb, 1, k);
        return sb.toString();
    }
}
```