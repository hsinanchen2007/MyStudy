![image.png](https://pic.leetcode-cn.com/f2e6eebea20420b2c63cafdd8f4f3b2f4a2c1dbd87de929a71b7eedbee4522fb-image.png)


```
'''
前缀树应用，前缀树每个节点保存三个字典序最小的单词
'''


class TrieNode:
    def __init__(self):
        self.s = ''
        self.next = {}
        self.is_end = False
        self.words = []

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def append(self, s: str):
        cur = self.root
        for ch in s:
            if ch not in cur.next:
                new_node = TrieNode()
                new_node.s = cur.s + ch
                cur.next[ch] = new_node

            cur = cur.next[ch]
            cur.words.append(s)
            cur.words.sort()
            if len(cur.words) == 4:
                cur.words.pop(-1)

        cur.is_end = True

    def getRoot(self) -> TrieNode:
        return self.root



from typing import List
class Solution:

    def dfs(self, root: TrieNode, s, pos, ans):
        if pos == len(s):
            return

        if s[pos] not in root.next:
            return

        words = root.next[s[pos]].words
        ans.append(words[:min(3, len(words))])

        self.dfs(root.next[s[pos]], s, pos+1, ans)

    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        trie = Trie()
        for w in products:
            trie.append(w)

        root = trie.getRoot()
        ans = []
        self.dfs(root, searchWord, 0, ans)

        while len(ans) < len(searchWord):
            ans.append([])

        return ans
```
