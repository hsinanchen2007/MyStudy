# 思路
1. 以words构建字典树
2. 按递减顺序选定单词宽度，逐行添加单词，同列字母需要位于字典树自顶点向下的路径中 （剪枝1）
3. 当 选定单词宽度 * 最长单词（即最长行数）< area，结束循环 （剪枝2）
```
class Trie:
    def __init__(self):
        self.root = [{}, False]
    
    def addWord(self, word):
        cur = self.root
        for c in word:
            if c not in cur[0]:
                cur[0][c] = [{}, False]
            cur = cur[0][c]
        cur[1] = True

class Solution:
    def maxRectangle(self, words: List[str]) -> List[str]:
        area = 0
        res = []
        trie = Trie()
        for word in words:
            trie.addWord(word)

        def dfs(arr, li):
            for word in words:
                if len(word) != len(arr):   continue
                for i, c in enumerate(word):
                    if c not in arr[i][0]: break
                else:
                    temp = arr[:]
                    flag = True
                    for i, c in enumerate(word):
                        temp[i] = temp[i][0][c]
                        flag &= temp[i][1]
                    li.append(word)
                    if flag:
                        h, w = len(li), len(word)
                        nonlocal area, res
                        if h * w > area:
                            area = h * w
                            res = li[:]
                    dfs(temp, li)
                    li.pop()

        ll = sorted(set(len(word) for word in words), reverse = True)
        for l in ll:
            if l * ll[0] < area:   break
            dfs([trie.root] * l, [])
        return res
```
