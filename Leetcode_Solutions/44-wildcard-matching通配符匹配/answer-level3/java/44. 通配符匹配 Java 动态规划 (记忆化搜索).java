### 代码

```java
/**
 * 动态规划
 * 从记忆化搜索的角度来讲更直观 (不过写代码可能还是递推更简洁)
 * s, p 从头一个个匹配, ? 通配很容易处理, 而 * 则需要枚举匹配 s 从当前位置起的多少个字符
 */
class Solution {
    private char[] s, p;
    private int[][] memo;   // 0 未计算, 1 true, 2 false TODO 浪费空间
    public boolean isMatch(String s, String p) {
        // 特判空字符串的情况
        if (p.length() == 0) {
            return s.length() == 0;
        }
        if (s.length() == 0) {
            for (int i = 0; i < p.length(); i++) {
                if (p.charAt(i) != '*') {
                    return false;
                }
            }
            return true;
        }

        this.s = s.toCharArray();
        // 预处理 p, 如果有连续的 * 则只保留 1 个
        StringBuilder sb = new StringBuilder();
        sb.append(p.charAt(0)) ;
        for (int i = 1; i < p.length(); i++) {
            if (p.charAt(i) != '*' || p.charAt(i - 1) != '*') {
                sb.append(p.charAt(i));
            }
        }
        this.p = sb.toString().toCharArray();
        int n = this.s.length, m = this.p.length;
        memo = new int[n + 1][m + 1];
        return dfs(0, 0);
    }

    private boolean dfs(int i, int j) {
        // 直接匹配, 直到遇见 * 或不相等
        while (i < s.length && j < p.length &&
                (s[i] == p[j] || p[j] == '?')) {
            i++;
            j++;
        }
        if (memo[i][j] > 0) {
            return memo[i][j] == 1;
        }
        // 若其中一个已经匹配完了
        if (i == s.length) {
            boolean res = j == p.length || (j == p.length - 1 && p[j] == '*');
            memo[i][j] = res ? 1 : 2;
            return res;
        }
        if (j == p.length) {
            memo[i][j] = 2;
            return false;
        }
        // 都还没匹配完, 但是不相等 TODO 可以和上一个if合并
        if (p[j] != '*' && s[i] != p[j]) {
            memo[i][j] = 2;
            return false;
        }
        // 枚举 * 应该匹配 s 中的多少个字符
        // 注意循环范围 i <= k <= s.length
        // k == i 对应一个也不匹配
        // k == s.length 对应把 s 中剩下的都匹配完
        for (int k = i; k <= s.length; k++) {
            if (dfs(k, j + 1)) {
                memo[i][j] = 1;
                return true;
            }
        }
        memo[i][j] = 2;
        return false;
    }
}

```