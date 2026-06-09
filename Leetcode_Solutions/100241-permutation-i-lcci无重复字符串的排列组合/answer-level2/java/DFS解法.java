### 解题思路
DFS解法，用visited数组标记是否已经访问过，不可重复使用一个字符。

### 代码

```java
class Solution {
    Set<String> set = new HashSet<>();

    public String[] permutation(String S) {
        if (S == null || S.length() == 0) {
            return new String[]{};
        }
        boolean[] visited = new boolean[S.length()];

        for (int i = 0; i < S.length(); i++) {
            visited[i] = true;
            dfs(S, S.charAt(i) + "", visited);
            visited[i] = false;
        }
        String[] results = new String[set.size()];
        Iterator iterator = set.iterator();
        int index = 0;
        while (iterator.hasNext()) {
            results[index++] = (String) iterator.next();
        }
        return results;
    }

    private void dfs(String target, String tmp, boolean[] visited) {
        if (tmp.length() == target.length()) {
            set.add(tmp);
            return;
        }
        for (int i = 0; i < target.length(); i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            tmp += target.charAt(i);
            dfs(target, tmp, visited);
            tmp = tmp.substring(0, tmp.length() - 1);
            visited[i] = false;
        }
    }
}
```