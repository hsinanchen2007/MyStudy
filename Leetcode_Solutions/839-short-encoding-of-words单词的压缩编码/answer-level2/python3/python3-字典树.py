### 解题思路
此处撰写解题思路

### 代码

```python3
class TrieNode:
    def __init__(self):
        self.nodes = dict()  # 构建字典
        self.is_leaf = False #是否是叶子节点/单词最后一个元素

    def insert(self, word: str): #插入一个单词字符串
            curr = self
            for char in word:
                if char not in curr.nodes:
                    curr.nodes[char] = TrieNode()
                curr = curr.nodes[char]
                curr.is_leaf=False
            curr.is_leaf = True

    def search(self, word:str):#搜索一个单词是否在字典树内
        curr = self
        for char in word:
            if char not in curr.nodes:
                return False
            curr = curr.nodes[char]
        if curr.is_leaf:
            return True
        return False

class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words = list(set(words))#去除重复单词
        words.sort(key= lambda i:len(i))#按照单词长度从小到大排序，包含短单词后缀的长单词能够把短单词结尾的is_leaf置false，从而删除了字典树内的短单词
        root = TrieNode()
        ans = 0
        for word in words:
            root.insert(word[::-1])
        for word in words:
            if root.search(word[::-1]):
                ans += len(word)+1
        return ans 
```