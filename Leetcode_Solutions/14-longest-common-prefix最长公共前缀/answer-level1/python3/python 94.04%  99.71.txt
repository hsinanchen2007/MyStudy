思路比较简单，利用当前的所有子串，构建字典树。
然后在字典树的基础上查找公共子串，结束条件为当前字典树的长度不为 1。具体见如下代码：
```
from collections import defaultdict

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if strs == None or len(strs) == 0:      # strs 为空
            return ""
        if len(set(strs)) == 1:     # 针对重复strs中都为重复的子串
            return strs[0]
        trie = defaultdict(str)
        res = ""
        index = 0
        for word in strs:       # 构建字典树
            curTrie = trie
            for c in word:
                curTrie = curTrie.setdefault(c, {})
            curTrie['end'] = 'end'
        while len(trie) == 1:       # 当前字典树长度不为1时结束
            res += strs[0][index]
            trie = trie[strs[0][index]]     # 进入下一个字典树
            index += 1
        return res
```
