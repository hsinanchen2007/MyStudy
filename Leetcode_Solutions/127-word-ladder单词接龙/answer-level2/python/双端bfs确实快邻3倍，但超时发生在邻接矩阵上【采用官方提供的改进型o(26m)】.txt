### 解题思路
    不用保存路径，代码要缩短一倍
    代码增加一倍时，bug成指数增长

### 代码

```python3
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        #tab是原始字符集，adj是hashmap的邻接矩阵，算是一种备忘录或懒加载策略吧
        def getNext(tab, adj, cur):
            if cur in adj: return adj[cur]
            res = set()
            for i in range(len(cur)):
                for c in range(0, 26):
                    s = cur[0:i]+chr(c+97)+cur[i+1:]
                    if s in tab and s!=cur: res.add(s)
            adj[cur] = res
            return res
        #双端搜索
        def bfs(tab, adj, s, e):
            path1, S1, step1 = [s], set([s]), 1
            path2, S2, step2 = [e], set([e]), 1
            while path1:
                #交换方向
                if len(path1)>len(path2):
                    path1,S1,step1,path2,S2,step2= path2,S2,step2,path1,S1,step1
                tmp, path1 = path1, []
                #从k层往前推进一层kk，kk在S2中，结束；kk在S1中，跳过；
                for k in tmp:
                    for kk in getNext(tab, adj, k):
                        if kk in S2: return step1 + step2
                        if kk in S1: continue
                        path1.append(kk)
                        S1.add(kk)
                step1 += 1
            return 0

        wordList.append(beginWord)
        tab, adj= set(wordList), {}
        #结束1
        if endWord not in tab : return 0
        #结束2
        return bfs(tab, adj, beginWord, endWord)
```