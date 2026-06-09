因为题目本身会保证括号嵌套有效且长度不为0，可以不用过多校验，
且只是将括号分成两份获取最小嵌套深度，个人理解大概近似为把深度对折的意思
即把连续加深的括号分到两份里
即相邻的两个同向括号会分配到两个不同组别里
又括号有效性，从‘（’开始，最近不同向括号的匹配原则，两个要在同一组里
即想到考虑相邻的两个括号是否相同进行判断。


```
public int[] maxDepthAfterSplit(String seq) {
        int len = seq.length();
        int[] ans = new int[len];
        char[] chs = seq.toCharArray();
        for (int i = 1; i < chs.length; i++) {
            if (chs[i] == chs[i - 1]) {
                ans[i] = 1 - ans[i - 1];
            } else {
                ans[i] = ans[i - 1];
            }
        }
        return ans;
    }
```
