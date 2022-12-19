

```
'''
从上往下看每一行，其实从第一行开始，只要添加了一行，相同下标的列就已经定了
后面再继续添加的行，必须满足已经确定数值位置的前缀要求，显然要用前缀树来搞
递归填充矩阵每一行，每一行填充时候再前缀树里面找候选即可
'''

from typing import List

class TrieNode:
    def __init__(self):
        self.s = ''
        self.next = {}
        self.is_end = False

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
        cur.is_end = True

    def getRoot(self) -> TrieNode:
        return self.root

    def dfs(self, root, ans):
        if root.is_end:
            ans.append(root.s)

        for next_node in root.next.values():
            self.dfs(next_node, ans)

    # 返回所有符合前缀的字符串
    def getAllPrefixWords(self, prefix, ans):
        root = self.root
        for ch in prefix:
            if ch not in root.next:
                return ans

            root = root.next[ch]

        self.dfs(root, ans)
        return ans

class Solution:

    def buildMatrix(self, cur_layer, cur_word, cur_matirx, trie, path, ans):
        path.append(cur_word)
        #print(f'path is {path}')

        if len(path) == len(cur_word):
            ans.append([w for w in path])
            path.pop(-1)
            return

        # 填写对应列的前缀
        n = len(cur_word)
        for i in range(cur_layer+1, n):
            cur_matirx[i][cur_layer] = cur_word[i]

        prefix = ''.join(cur_matirx[cur_layer+1][:cur_layer+1])
        next_words = [w for w in trie.getAllPrefixWords(prefix, []) if len(w) == len(cur_word)]
        for next in next_words:
            self.buildMatrix(cur_layer+1, next, cur_matirx, trie, path, ans)

        path.pop(-1)

    def wordSquares(self, words: List[str]) -> List[List[str]]:
        trie = Trie()
        for w in words:
            trie.append(w)

        all_len = [len(w) for w in words]
        max_len = max(all_len)

        ans = []
        matrix = [['' for _ in range(max_len)] for _ in range(max_len)]
        for w in words:
            self.buildMatrix(0, w, matrix, trie, [], ans)
        return ans

```
