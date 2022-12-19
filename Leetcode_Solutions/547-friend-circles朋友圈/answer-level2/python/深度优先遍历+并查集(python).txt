解法1：深度优先遍历，用集合存储已经访问过的节点，如果访问过则跳过，否则朋友圈+1
```
   def findCircleNum(self, M):
        visited, ans = set(), 0

        def dfs(i):
            for j in range(len(M[i])):
                if M[i][j] and j not in visited:
                    visited.add(j)
                    dfs(j)

        for i in range(len(M)):
            if i not in visited:
                dfs(i)
                ans += 1
        return ans
```

解法2：并查集。首先每个人都是自己的朋友圈，所以先建立一个对应关系指向自己。
如果i和j是朋友，则i的朋友圈合并j的朋友圈，即j所在圈的根节点指向i所在圈的根节点。
最后数一下指向自己的节点有几个，即根节点的数量，即朋友圈的数量

```
    def findCircleNum2(self, M):  
        n = len(M)
        circles = {i: i for i in range(n)}

        def find(i):
            if i == circles[i]:
                return i
            circles[i] = find(circles[i])
            return circles[i]

        for i in range(n):
            for j in range(i + 1, n):
                if M[i][j] == 1:
                    circles[find(i)] = find(j)

        return sum([1 for k, v in circles.items() if k == v])
```