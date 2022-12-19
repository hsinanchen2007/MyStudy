![image.png](https://pic.leetcode-cn.com/1b252e5f5cb30f7e7781bf988dc07e4f1e48146890051fb78b9470070736c6ea-image.png)


```
'''
前缀树解决，每个字符串用/分割成序列，把所有序列全部加前缀树，
然后再遍历一遍序列，用每个序列在前缀树里面dfs, 检查序列是不是
最短的前缀
'''



class TrieNode:
    def __init__(self):
        self.next = {}
        self.is_end = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def append(self, val_list):
        cur = self.root
        for val in val_list:
            if val not in cur.next:
                new_node = TrieNode()
                cur.next[val] = new_node
            cur = cur.next[val]
        cur.is_end = True

    def getRoot(self) -> TrieNode:
        return self.root

from typing import List
class Solution:

    def isShortestPrefix(self, trie, s: str):
        cur = trie.getRoot()
        val_list = s.split('/')[1:]

        i = 0
        while True:
            cur = cur.next[val_list[i]]
            if cur.is_end:
                break
            i += 1

        return i == len(val_list)-1

    def removeSubfolders(self, folder: List[str]) -> List[str]:
        trie = Trie()
        for f in folder:
            trie.append(f.split('/')[1:])

        ans = []
        for f in folder:
            if self.isShortestPrefix(trie, f):
                ans.append(f)

        return ans
```
