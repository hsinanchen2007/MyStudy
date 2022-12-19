![image.png](https://pic.leetcode-cn.com/d66a218dc5b9ab0fd9718b1a9952e82a2b59757579aac0ad3e82124cd76f1fb0-image.png)


```

'''
把每个字符串的逆序加入前缀树，前缀树end节点存原始顺序字符串
然后迭代每个单词，利用前缀树找所有逆序后缀跟当前单词一样的单词，
只有这种单词才可能跟当前单词配成回文
'''


class TrieNode:
    def __init__(self):
        self.s = ''
        self.next = {}
        self.is_end = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def append(self, s: str):
        if s == '':
            self.root.is_end = True
            self.root.s = ''
            return

        cur = self.root
        for ch in reversed(s):
            if ch not in cur.next:
                new_node = TrieNode()
                cur.next[ch] = new_node
            cur = cur.next[ch]

        cur.is_end = True
        cur.s = s

    def getRoot(self) -> TrieNode:
        return self.root


from typing import List
class Solution:

    def dfs(self, root: TrieNode, words, flag):
        if flag and root.is_end:
            words.append(root.s)

        for next in root.next.values():
            self.dfs(next, words, True)

    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        trie = Trie()
        str2idx = {}
        for i, w in enumerate(words):
            str2idx[w] = i
            trie.append(w)

        ans = []
        for w in words:
            cur = trie.getRoot()
            flag = True

            if cur.is_end:
                if w != cur.s:
                    sum_str = w + cur.s
                    if sum_str == sum_str[::-1]:
                        ans.append([str2idx[w], str2idx[cur.s]])

            for ch in w:
                if ch not in cur.next:
                    flag = False
                    break

                cur = cur.next[ch]
                if cur.is_end:
                    if w != cur.s:
                        sum_str = w + cur.s
                        if sum_str == sum_str[::-1]:
                            ans.append([str2idx[w], str2idx[cur.s]])


            if flag == False:
                continue

            # w 是作为比较短的单词放在回文前面的，需要继续dfs把可能的后面半边子串从Trie里面全部读出来尝试
            possible_suffix = []
            self.dfs(cur, possible_suffix, False)
            for suffix in possible_suffix:
                if w != suffix:
                    sum_str = w + suffix
                    if sum_str == sum_str[::-1]:
                        ans.append([str2idx[w], str2idx[suffix]])

        return ans
```
