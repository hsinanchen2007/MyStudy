

```
'''
先把字符串可能的缩写都枚举出来，然后按照缩写的长度进行升序排序
把所有字典里面单词全部放入前缀树
从长度最小的缩写开始枚举，将其转换为一个模式串， 例如w2d 转换为w**d
然后用模式串在前缀树里面匹配，如果匹配到单词说明缩写冲突
找最小的不会出现冲突的缩写
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


from typing import List
class Solution:

    def dfs(self, cur: int, s: str, path: List[str], short_words):
        if cur == len(s):
            #print(''.join(path))
            ans = ''
            for ch in path:
                if ch.isalpha():
                    ans += ch
                else:
                    ans += '*' * int(ch)
            #print(ans)
            short_words.append((''.join(path), ans, len(path)))

            return

        path.append(s[cur])
        self.dfs(cur+1, s, path, short_words)
        path.pop(-1)

        if len(path) == 0 or not path[-1].isdigit():
            for i in range(1, len(s) - cur + 1):
                path.append(str(i))
                self.dfs(cur+i, s, path, short_words)
                path.pop(-1)


    def findMatch(self, cur, pat: str, root: TrieNode):
        if cur == len(pat):
            return root.is_end

        ch = pat[cur]
        if ch != '*':
            return self.findMatch(cur+1, pat, root.next[ch]) if ch in root.next else False
        else:
            for next_node in root.next.values():
                if self.findMatch(cur+1, pat, next_node):
                    return True

        return False

    def minAbbreviation(self, target: str, dictionary: List[str]) -> str:
        if len(dictionary) == 0:
            return str(len(target))

        short_str = []
        self.dfs(0, target, [], short_str)
        short_str.sort(key = lambda x : x[2])
        #print(short_str)

        trie = Trie()
        for w in dictionary:
            if len(w) == len(target):
                trie.append(w)

        for short, pat, _ in short_str:
            #print(short, pat)
            if not self.findMatch(0, pat, trie.getRoot()):
                return short

        return ''
```
