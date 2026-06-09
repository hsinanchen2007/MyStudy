![image.png](https://pic.leetcode-cn.com/1dae7d973cd26e25e80861c8ad677aec76573ec8a5bdf4a0c608e7291d5fda94-image.png)


```
'''
两次dfs 第一次找一个度为1的节点，找距离它最远的节点
这个节点作为第二次dfs起点，再找一次距离最远的节点
第二次得出的最长路径长度就是答案
'''

from typing import List
from collections import Counter
class Solution:

    def dfs(self, cur, start, c: Counter, link, path_len: int, visited, ans: List[int]):
        #print(cur, path_len)

        if cur in visited:
            return

        if c[cur] == 1 and cur != start:
            if path_len > ans[1]:
                ans[0] = cur
                ans[1] = path_len
            return

        visited.add(cur)
        for next in link[cur]:
            self.dfs(next, start, c, link, path_len+1, visited, ans)
        visited.remove(cur)

    def treeDiameter(self, edges: List[List[int]]) -> int:
        c = Counter()
        link = {}
        for s, e in edges:
            c[s] += 1
            c[e] += 1

            if s not in link:
                link[s] = []
            link[s].append(e)

            if e not in link:
                link[e] = []
            link[e].append(s)

        ans = [1]
        for k, v in c.items():
            if v == 1:
                ans = [0, 0]        # [终点，最长路径长度]
                self.dfs(k, k, c, link, 0, set(), ans)

                start = ans[0]
                # 第二次dfs, 上一次求出来的最长路径终点作为起点，再找一次最长路径
                ans = [0, 0]  # [终点，最长路径长度]
                self.dfs(start, start, c, link, 0, set(), ans)
                return ans[1]
```
