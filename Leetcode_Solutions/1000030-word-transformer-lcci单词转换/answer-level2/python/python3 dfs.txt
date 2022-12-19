### 解题思路
先建立通配符映射，之后采用dfs，搜索过程中建立marked标记计算过的节点。

### 代码

```python3
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[str]:
        picture_dic = collections.defaultdict(set)


        for word in wordList:
            for i in range(len(word)):
                picture_dic[word[:i]+'*'+word[i+1:]].add(word)

        self.res = []
        def dfs(cur,tmp_res,marked):
            if cur==endWord:
                self.res = tmp_res
                return 
            
            for i in range(len(cur)):
                for word in picture_dic[cur[:i]+'*'+cur[i+1:]]:
                    if word not in marked:
                        marked.add(word)
                        dfs(word,tmp_res+[word],marked)
                        
        dfs(beginWord,[],{beginWord})
        
        return [beginWord]+self.res if self.res else self.res
        
        
        
        
        
        
        

```