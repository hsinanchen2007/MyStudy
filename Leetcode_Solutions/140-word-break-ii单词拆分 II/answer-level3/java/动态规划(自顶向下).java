## 思路:

动态规划:

自顶向下:

参照[139. 单词拆分](https://leetcode-cn.com/problems/word-break/) | [题解链接](https://leetcode-cn.com/problems/word-break/solution/dong-tai-gui-hua-zi-ding-xiang-xia-he-zi-di-xiang-)



相关题型:[139. 单词拆分](https://leetcode-cn.com/problems/word-break/)

## 代码:

思路一:

```python []
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        import functools
        if not wordDict:return []
        wordDict = set(wordDict)
        max_len = max(map(len, wordDict)) 
        @functools.lru_cache(None)
        def helper(s):
            res = []
            if not s:
                res.append("")
                return res
            for i in range(len(s)):
                if i < max_len and s[:i+1] in wordDict: 
                    for t in helper(s[i+1:]):
                        if not t:
                            res.append(s[:i+1])
                        else:
                            res.append(s[:i+1] + " " + t)
            return res    
        return helper(s)
```


```java []
class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        int max_len = 0;
        for (String word : wordDict) max_len = Math.max(max_len, word.length());
        return helper(s, max_len, wordDict, new HashMap<String, LinkedList<String>>());
    }

    private List<String> helper(String s, int max_len, List<String> wordDict, HashMap<String, LinkedList<String>> cache) {
        if (cache.containsKey(s)) return cache.get(s);
        LinkedList<String> res = new LinkedList<>();
        if (s.length() == 0) {
            res.add("");
            return res;
        }
        for (int i = 0; i < s.length(); i++) {
            if (i < max_len && wordDict.contains(s.substring(0, i + 1))) {
                for (String tmp : helper(s.substring(i + 1), max_len, wordDict, cache))
                    res.add(s.substring(0, i + 1) + (tmp.isEmpty() ? "" : " ") + tmp);
            }
        }
        cache.put(s, res);
        return res;
    }
}
```

