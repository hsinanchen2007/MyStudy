```
class Solution:
    def getValidT9Words(self, num: str, words: List[str]) -> List[str]:
        hashamap = {'2':['a','b','c'],
                    '3':['d','e','f'],
                    '4':['g','h','i'],
                    '5':['j','k','l'],
                    '6':['m','n','o'],
                    '7':['p','q','r','s'],
                    '8':['t','u','v'],
                    '9':['w','x','y','z']}   
        #构建前缀树
        trie = {}
        for word in words:
            curNode = trie
            for c in word:
                curNode.setdefault(c, {})
                curNode = curNode[c]
            curNode['end'] = word
        
        res = []
        #深度搜索，每一个数字对应的字母展开搜索
        def dfs(word, i, node):
            for s in hashamap[word[i]]:
                if s not in node:
                    continue
                curNode = node[s]
                if i == len(word)-1:
                    if 'end' in curNode:
                        res.append(curNode['end'])
                    else:
                        return
                if i < len(word)-1:
                    dfs(word, i+1, curNode)
        dfs(num, 0, trie)
        return res
```
