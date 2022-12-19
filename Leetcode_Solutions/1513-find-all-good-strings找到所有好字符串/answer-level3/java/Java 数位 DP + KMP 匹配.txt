前面已经有人指出此题涉及到数位 DP 的知识, 数位 DP 的介绍和模板可以看此链接: [https://oi-wiki.org/dp/number/](https://oi-wiki.org/dp/number/).

对于字典序大于等于 `s1` 小于等 `s2` 区间内查找好字符串的问题, 可以将其转化为字典序小于等于 `s2` 的区间内好字符串的个数减去字典序小于 `s1` 的区间内好字符串的个数.

方便起见我们将字典序上界字符串称为 `s`, 坏字符串称为 `evil`, 当前正在尝试的字符串为 `current`. 我们维护一个 `dp[index][match]` 二维表来表示当前可能的好字符串的构建状态, 其中 `index` 表示当前字符串 `current` 正待确定 `current[index]` 位 (即 `[0, ..., index-1]` 已经确定). `match` 表示 `evil` 字符串正待匹配 `evil[match]` 位 (即 `evil[0, ..., match-1]` 位已经与 `current[index-match, ..., index-1]` 匹配). 除此以外数位 DP 还有一个重要的属性 `threshold` (也就是上面链接里模板的 `op`), 表示 `current` 与 `s` 当前确定的前缀之间的关系, 如果 `current[0, ..., index-1] == s[0, ..., index-1]` 则 `threshold` 为真, 表示当前确定的前缀相等.

基于上述构造, 我们可以很容易地写出状态间的转移关系, 首先通过 `evil` 字符串求出其 KMP 算法中的 `next` 数组, `nextMatchPoint` 表示当前尝试的匹配位点为 `match` 时下一个尝试的匹配位点, 当 `match` 匹配到 `evil` 尾部时表示 `current` 为坏字符串, 不用再递归其子问题了. 所以对于 `current` 字符串当前 `index` 位的任意可行字符 `c`, `dp[index][match]` 的值为 `dp[index+1][nextMatchIndex(evil, match, c)]` 求和.

完整代码如下, 注意并没有显式地构造 `current`, 因为其内容不重要, 我们关心的是 `index` 和 `match`:

```java
class Solution {
  int[][] dp;
  int[] next; // KMP 算法中的 next 数组
  int mod = (int) 1e9 + 7;

  int[] getNext(String s) {
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

  // 对于字符串 pattern, 当前正在尝试用 c 匹配 pattern[index], 求下一个尝试的匹配位点
  int nextMatchPoint(char[] pattern, int index, char c) {
    while (index > 0 && pattern[index] != c)
      index = next[index]; // 不匹配, 下一个匹配位点为 next[index]
    if (pattern[index] == c)
      index++; // 匹配, 下一个匹配位点为 index + 1
    return index;
  }

  int dfs(char[] s, int index, char[] evil, int match, boolean threshold) {
    int n = s.length;
    if (index == n)
      return 1; // current
    if (!threshold && dp[index][match] != 0)
      return dp[index][match];
    char max = threshold ? s[index] : 'z'; // 如果现有前缀小于 s 中对应前缀, 则 a~z 都可以取, 否则只能取 a~s[index]
    int result = 0;
    for (char c = 'a'; c <= max; c++) {
      if (evil[match] == c && match == evil.length - 1) // current 中出现了坏字符串
        continue;
      result += dfs(s, index + 1, evil, nextMatchPoint(evil, match, c), threshold && c == max); 
      result %= mod;
    }
    if (!threshold)
      dp[index][match] = result; // 记忆化
    return result;
  }

  public int findGoodStrings(int n, String s1, String s2, String evil) {
    next = getNext(evil);
    dp = new int[s1.length()][evil.length()];
    int v1 = dfs(s1.toCharArray(), 0, evil.toCharArray(), 0, true);
    dp = new int[s2.length()][evil.length()];
    int v2 = dfs(s2.toCharArray(), 0, evil.toCharArray(), 0, true);
    return (v2 - v1 + (s1.contains(evil) ? 0 : 1) + mod) % mod; // 因为 v2 - v1 是左开右闭, 需要特判 s1 是否可行
  }
}
```
