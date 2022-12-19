非常好的题目,首先题目读完应该能想到要用数位dp，然后关键的点就是字符串匹配的时候**并不是**两个字符串从头开始匹配，匹配不上就gg了。而是要让这里的模式串evil回退（其实就是kmp思想了）
```
    private int[] next;
    private int[] getNext4(String s) {
        int[] next = new int[s.length() + 1];
        int i = 0, j = -1;
        next[0] = -1;
        while (i < s.length()) {
            if (j == -1 || s.charAt(j) == s.charAt(i))
                next[++i] = ++j;
            else
                j = next[j];
        }
        next[0] = 0; // 此处将 next[0] 置为 0 方便逻辑统一
        return next;
    }
    public int findGoodStrings(int n, String s1, String s2, String evil) {
        next = getNext4(evil);
        int res1 = solve(s1, evil);
        int res2 = solve(s2, evil);
        return (res2 - res1 + 1000000007+ (s1.contains(evil) ? 0 : 1)) % 1000000007;

    }

    private int[][] findGoodStringsDp;

    private int solve(String string, String evil) {
        findGoodStringsDp = new int[string.length()][evil.length()];
        for (int i = 0; i < findGoodStringsDp.length; i++) {
            Arrays.fill(findGoodStringsDp[i], -1);
        }
        return dfs(0, true, 0, evil, string);
    }

    private int nextMatch(int index, String evil, char c) {
        while (index != 0 && evil.charAt(index) != c) {
            index = next[index];
        }
        if (evil.charAt(index) == c) {
            index++;
        }
        return index;
    }

    private int dfs(int pos, boolean limit, int match, String evil, String string) {
        int modulo = 1000000007;

        if (pos == string.length()) return 1;
        if (!limit && findGoodStringsDp[pos][match] != -1) return findGoodStringsDp[pos][match];
        int up = limit ? string.charAt(pos) : 'z';
        int tmp = 0;
        for (int i = 'a'; i <= up; i++) {
            if (evil.charAt(match) != i || match != evil.length() - 1)  {
                tmp =(tmp%modulo) + (dfs(pos + 1, limit && i == string.charAt(pos), nextMatch(match, evil,(char)i), evil, string) % modulo);
                tmp %= modulo;
            }
        }
        if (!limit) findGoodStringsDp[pos][match] = tmp;
        return tmp;
    }
```
