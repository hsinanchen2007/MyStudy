### 解题思路
此处撰写解题思路

### 代码

```python3
import collections
class Solution:
    def getNext(self, cur, tab, adj):
        if cur in adj: return adj[cur]
        res = set()
        for i in range(len(cur)):
            for c in range(0, 26):
                s = cur[0:i]+chr(c+97)+cur[i+1:]
                if s in tab and s != cur: res.add(s)
        adj[cur] = res
        return res;

    #双端bfs
    def bfs(self, tab, adj, s, e):
        # 拼接path和path2路径：python没能找到跳出多层循环方法
        def catPath(path, path2, s):
            del path[-1]
            if s == path2[0][0]: path,path2 = path2,path
            for i in path2[::-1]:path.append(i)
            return path

        S, path = set([s]), [[s]]
        S2, path2 =  set([e]), [[e]]
        while path[-1]:
            # 交换搜索方向
            if len(path[-1])>len(path2[-1]):
                S,path,S2,path2 = S2,path2,S,path
            path.append([])
            # 从当前层级往前推进一层：下一层节点出现在S2中，结速；下一层节点出现在S中，跳过；加入
            for k in path[-2]:
                for kk in self.getNext(k, tab, adj):                    
                    if kk in S2: return catPath(path, path2, s)
                    if kk in S: continue
                    path[-1].append(kk)
                    S.add(kk)
        return catPath(path, path2, s)
    
    #寻找pth路径
    def dfs(self, tab, adj, path, step, p, res):
        if step==-1:
            res.append(p[::-1])
            return
        for i in path[step]:
            if i in self.getNext(p[-1], tab, adj):
                p.append(i)
                self.dfs(tab, adj, path, step-1, p, res)
                p.pop()

    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        wordList.append(beginWord)
        adj, tab = {}, set(wordList)
        # 提前结束1
        if endWord not in tab:
            return []
        # 提前结束2
        self.getNext(endWord, tab, adj)
        self.getNext(beginWord, tab, adj)
        if not adj[beginWord] or not adj[endWord]:
            return []
        # 一定有答案
        path = self.bfs(tab, adj, beginWord, endWord);
        res = []
        self.dfs(tab, adj, path, len(path)-2, [endWord], res )
        
        return res
```