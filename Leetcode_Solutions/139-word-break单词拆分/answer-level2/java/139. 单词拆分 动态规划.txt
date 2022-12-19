### 比较简单的动态规划问题

```java
/**
 * 动态规划
 * 定义状态: f[i] 表示 s 的前 i 个字符组成的子串能否拼接而成
 * 状态转移: f[i] = OR f[i - j] (或和, j 表示 wordDict 中能与s[i-j:i]匹配的一个单词的长度)
 * 初始状态: f[0] = true
 */
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length(); 
        boolean[] f = new boolean[n + 1];
        f[0] = true;
        for (int i = 1; i <= n; i++) {
            for (String word : wordDict) {
                int j = word.length();
                if (i >= j && s.substring(i - j, i).equals(word) && f[i - j]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
}
```