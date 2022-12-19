## 思路:

如果我们知道结果中第一个单词，那么下一个单词前缀我们是知道的。

比如有`[ball]`，我们知道单词方块是 `4X4`，换句话说每个单词长度都为`4`，其次下个单词是`a`字母开头的。

假如我们找到一个`a`开头长度为`4`单词，变成`[ball, area]`，那么第三个单词的前缀是`le`长度为`4`单词，依次类推。

所以，我们通过前缀树找那些前缀单词，回溯找到所有解。

```python
class Solution:
    def wordSquares(self, words: List[str]) -> List[List[str]]:

        lookup = {}
        res = []
        for word in words:
            cur = lookup
            for w in word:
                cur.setdefault(w, {})
                cur = cur[w]
            # 单词结束标志
            cur["#"] = "#"

        
        # 寻找有prefix前缀长度为l的单词
        def helper(prefix, l):
            ans = []
            cur = lookup
            for p in prefix:
                if p not in cur:
                    return ans
                cur = cur[p]

            def dfs(prefix, cur):
                if "#" in cur and len(prefix) == l:
                    ans.append(prefix)
                    return
                if len(prefix) > l:
                    return

                for b in cur:
                    if b != "#":
                        dfs(prefix + b, cur[b])

            dfs(prefix, cur)
            return ans

        def backtrack(tmp, _len):
            # 数组里个数
            tmp_len = len(tmp)
            if tmp_len == _len:
                res.append(tmp)
                return
            # 目前列表的前缀
            prefix = ""
            for t in tmp:
                prefix += t[tmp_len]
            for nxt in helper(prefix, _len):
                backtrack(tmp + [nxt], _len)

        for word in words:
            backtrack([word], len(word))
        return res
```



