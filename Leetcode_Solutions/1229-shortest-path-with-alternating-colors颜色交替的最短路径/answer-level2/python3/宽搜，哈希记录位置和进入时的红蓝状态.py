上周去玩了没赶上周赛，虚拟赛里大约十几二十分钟做的吧。

我这里是用True和False记录红蓝位置，一些同学是用0,1或r,b记录红蓝位置，本质上没啥区别，理论上bool类型空间最低罢了，代码的执行速度还算凑合吧，看提交报告里，搞py3的只有一个60ms的神仙排在俺前面。

![image.png](https://pic.leetcode-cn.com/4228e1c62323a46eabb2c99fe7983ea3f6f00d63eebb580da71310eb144a1070-image.png)

```
class Solution(object):
    def shortestAlternatingPaths(self, n, red_edges, blue_edges):
        d = {}      #路径哈希
        for i,j in red_edges:
            if i not in d:
                d[i] = {True:[], False:[]}
            d[i][True] += [j]
        for i,j in blue_edges:
            if i not in d:
                d[i] = {True:[], False:[]}
            d[i][False] += [j]
        
        c={(0, True):0, (0, False):0}       #访问记录
        
        q = c.copy()        #初始队列
        while q:
            t = {}
            for i,j in q:
                if i in d:
                    for k in d[i][not j]:       #交替调用路径
                        if (k,not j) not in c:
                            c[(k, not j)] = c[(i, j)] + 1
                            t[(k, not j)] = c[(k, not j)]
            q = t

        ans = [-1] * n
        for i, j in c:
            if ans[i] == -1:
                ans[i] = c[(i, j)]
            else:
                ans[i] = min(ans[i], c[(i, j)])
            
        return ans
```
