## 思路:

动态规划

思路一:自顶向下, 

思路二:自底向上,

`dp[i]`表示`s`到`i`位置是否可以由`wordDict`组成

所以有 如果`dp[i - j]`是`true`并且`s[j:i]`在`wordDict`里, 那么`dp[i] = true`;

两种都很容易理解的!看代码就行了

------

相关题型: [140. 单词拆分 II](https://leetcode-cn.com/problems/word-break-ii/)

## 代码:

思路一:

```python [1]
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        import functools
        wordDict = set(wordDict)
        if not wordDict:return not s
        # 找最长单词的长度
        max_len = max(map(len, wordDict)) 
        @functools.lru_cache(None)
        def helper(s):
            # 递归终止条件
            if not s:
                return True
            for i in range(len(s)):
                # 判断是否满足条件
                if i < max_len and s[:i+1] in wordDict and helper(s[i+1:]):
                    return True
            return False
        return helper(s)
```



```java [1]
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int max_len = 0;
        for (String word : wordDict) max_len = Math.max(max_len, word.length());
        return helper(s, max_len, wordDict, new HashMap<String, Boolean>());

    }

    private boolean helper(String s, int max_len, List<String> wordDict, HashMap<String, Boolean> cache) {
        if (cache.containsKey(s)) return cache.get(s);
        if (s == null || s.length() == 0) return true;
        for (int i = 0; i < s.length(); i++) {
            if (i < max_len && wordDict.contains(s.substring(0, i + 1)) && helper(s.substring(i + 1), max_len, wordDict, cache)) {
                cache.put(s, true);
                return true;
            }
        }
        cache.put(s, false);
        return false;
    }
}
```

思路二:

```python [2]
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        if not wordDict: return not s
        dp = [False] * (n + 1)
        dp[0] = True
        for i in range(1, n + 1):
            for j in range(i - 1, -1, -1):
                if dp[j] and s[j:i] in wordDict:
                    dp[i] = True
                    break
        return dp[-1]
```



```java [2]
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        if (wordDict == null || wordDict.size() == 0) return s.isEmpty();
        int n = s.length();
        boolean[] dp = new boolean[n + 1];
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && wordDict.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
}
```

