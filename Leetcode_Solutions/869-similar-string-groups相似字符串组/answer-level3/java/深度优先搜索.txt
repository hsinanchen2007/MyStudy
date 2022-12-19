```java
class Solution {
    public int numSimilarGroups(String[] strings) {
        if (strings == null || strings.length == 0) {
            return 0;
        }
        if (strings[0].length() == 0) {
            return 0;
        }
        int ans = 0;
        int[] group = new int[strings.length];
        boolean[] visited = new boolean[strings.length];
        for (int i = 0; i < group.length; i++) {
            group[i] = i;
        }
        for (int i = 0; i < strings.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(strings, i, group, visited);
            }
        }
        Arrays.sort(group);
        int pre = -1;
        for (int n : group) {
            if (n != pre) {
                ans++;
                pre = n;
            }
        }
        return ans;
    }

    private void dfs(String[] strings, int i, int[] group, boolean[] visited) {
        for (int j = 0; j < strings.length; j++) {
            if (visited[j]) {
                continue;
            }
            if (strings[i].equals(strings[j]) || isSimilar(strings[i], strings[j])) {
                visited[j] = true;
                group[j] = group[i];
                dfs(strings, j, group, visited);
            }
        }
    }

    private boolean isSimilar(String s, String r) {
        int n = s.length();
        char[] chars;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) != r.charAt(i)) {
                char c = r.charAt(i);
                chars = s.toCharArray();
                for (int j = i + 1; j < s.length(); j++) {
                    if (chars[j] != r.charAt(j)) {
                        if (chars[j] == c) {
                            chars[j] = s.charAt(i);
                            chars[i] = c;
                            return r.equals(new String(chars));
                        } else {
                            return false;
                        }
                    }

                }
            }
        }
        return false;
    }
}
```
