找到所有与当前节点有关系的点，深度优先
i 代表人，0，1，，，n-1
在DFS中 判断条件：第i个人在的行，找出和i有关系的所有人；并且这个人还不在已有的朋友圈中。
满足条件后， 把新的有关系的朋友加入fri。
如果1和2是朋友，再找2的朋友3，依次类推，直到把所有的朋友找全，加入朋友圈，计数1；不在这个朋友圈的人继续判断
```
```python []
class Solution(object):
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        n = len(M)
        ##res 最后结果
        res = 0
        fri = set()
        def DFS(i):
            for row in range(n):
                if M[i][row] >=1 and row not in fri:
                    fri.add(row)
                    DFS(row)       
        for i in range(n):
            if i not in fri:
                res +=1
                DFS(i)
        return res
```


