```python3
# 前缀树,leetcode 208
class TrieNode:
    def __init__(self):
        self.children = {}
        self.isWord = False

class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        self.root = TrieNode()									#构建前缀树，Leetcode 208
        for word in words:
            if word:                                            #测试用例中有空字符，需要过滤掉
                node = self.root
                for i in word: 
                    if i not in node.children:
                        node.children[i] = TrieNode()
                    node = node.children[i]
                node.isWord = True
        
        #每个字符都dfs
        # def dfs2(word, node, idx, count):                       #count是单词数
        #     if idx == len(word):                                #边界条件，跑到最后，看看是不是一个单词结尾，同时单词超过1个，只有1个的话，不算连接词
        #         return node.isWord and count>0
        #     if node.isWord:                                     #每次到一个单词结束节点，dfs，count+1
        #         if dfs2(word, self.root, idx, count+1):         #重置node到根，看看下一个字符在不在开头，cats: 位置t的时候看看s在不在根的chrildren中，不在的话，就不该在这里算一个单词
        #             return True
        #     if word[idx] not in node.children:
        #         return False
        #     else:
        #         return dfs2(word, node.children[word[idx]], idx+1, count)    #更新节点，处理下一个字符

        #只在每个单词结尾dfs
        def dfs(word, index, count):
            node = self.root
            for i in range(index, len(word)):
                if word[i] not in node.children:
                    return False
                node = node.children[word[i]]
                if node.isWord:
                    if i == len(word)-1:
                        return count>=1
                    if dfs(word, i+1, count+1):                 #指针指向下一个字符，单词数+1
                        return True
            return False

        re = []
        for word in words:
            # if dfs2(word, self.root, 0, 0):                    #dfs2,这个每个字符都dfs一次
            if dfs(word, 0, 0):
                re.append(word)
        return re
```
