解法一：字典树

```
class TrieNode:
    # Initialize your data structure here.
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.is_word = False
class Trie:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()
        self.cnt = 0
        
    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        curCnt = 0
        isNew = False
        current = self.root
        for letter in word:
            if letter not in current.children:
                isNew = True
            current = current.children[letter]
        if isNew:
            self.cnt += len(word) + 1
        current.is_word = True
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        trie = Trie()
        words = list(set(words))
        words = sorted(words, key = lambda x : -len(x))
        for i in range(len(words)):
            trie.insert(words[i][::-1])
        return trie.cnt
```
对于```self.children = collections.defaultdict(TrieNode)```的理解：
对于每一个TrieNode，建立一个字典，字典的key即为字符串中的字符，每个字符又指向一个TrieNode，即字典的value。所以在TrieNode类中，children的边即为字典的key，而指向的node即为字典的value。
前缀树模板实现引用于以下博客：https://blog.csdn.net/IOT_victor/article/details/88936762
解法二：
```
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
    if not words:
            return 0
        if len(words) == 1:
            return len(words[0]) + 1
        words = [c[::-1] for c in words]
        words.sort()
        res = 0
        for i in range(len(words)-1):
            if self.match(words[i], words[i+1]):
                continue
            else:
                res += len(words[i]) + 1
        return res + len(words[-1]) + 1

    def match(self, s, t):
        for i in range(len(s)):
            if s[i] != t[i]:
                return False
        return True
```
将列表中的字符串反转后按字典序排列，依次看前一个字符串是不是后一个的前缀，如果不是，则加入最后的生成字符串中。该思路来自于：https://leetcode-cn.com/problems/short-encoding-of-words/solution/wu-xu-zi-dian-shu-qing-qing-yi-fan-zhuan-jie-guo-j/