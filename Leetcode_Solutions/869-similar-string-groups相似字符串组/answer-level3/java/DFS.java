套路题, 类似求连通分量, 使用 visited 数组, 如果是anagram则标记。

```
    public int numSimilarGroups(String[] A) {
        if (null == A || A.length == 0) {
            return 0;
        }
        int count = 0;
        int[] visited = new int[A.length];
        for (int i = 0; i < A.length; i++) {
            if (visited[i] == 0) {
                count++;
                dfs(A, visited, i);
            }
        }
        return count;
    }

    private void dfs(String[] A, int[] visited, int i) {
        visited[i] = 1;
        for (int j = 0; j < A.length; j++) {
            if (visited[j] == 0 && isAnagram(A[i], A[j])) {
                dfs(A, visited, j);
            }
        }
    }

    private boolean isAnagram(String s1, String s2) {
        if (null == s1 && null == s2) {
            return true;
        }
        if (s1.length() != s2.length()) {
            return false;
        }
        if (s1.equals(s2)) {
            return true;
        }
        int diff = 0;
        for (int i = 0; i < s1.length() && diff <=2; i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                diff++;
            }
        }
        return diff == 2;
    }


```
