![image.png](https://pic.leetcode-cn.com/666012d3a71549502762bd4333a58bf4d1311f794079b6f77b968cd79156730b-image.png)

```python
class Solution:
    def multiSearch(self, big, smalls):
        # build trie tree
        trie_tree = {}
        for i, word in enumerate(smalls):
            tree = trie_tree
            for c in word:
                if c not in tree:
                    tree[c] = {}
                tree = tree[c]
            tree[-1] = i  # 单词结束标志，同时记录 small 单词索引
        # search
        res = [[] for _ in range(len(smalls))]
        for i in range(len(big)):
            tree = trie_tree
            for j in range(i, len(big)):
                if big[j] not in tree:
                    break
                tree = tree[big[j]]
                if -1 in tree:
                    res[tree[-1]].append(i)
        return res
```