### 解题思路
**回溯法其实就是对一个树形图的深度遍历dfs**
**我们在每次进行回溯的时候需要对每个点保存两个变量**
**1、path:局部变量，记录了包含了当前节点的路径（包含了当前节点）**
**2、res:全局变量，记录满足条件的所有路径**

##### 看下图，我们把问题转换成树形图，问题将很清晰明了，相当于直接对树进行DFS， 这里每个节点相当于到该节点时的路径！！

![image.png](https://pic.leetcode-cn.com/9ac7d021aa5588b88ff3584f0d7aaa12d77103de00d2a0221bcbde3f7eb62e31-image.png)

##### 有帮助的话，点个赞

### 代码

```python3
class Solution:
    def permutation(self, S: str) -> List[str]:
        if S == '':return []
        res = []
        path = ''
        def backtrack(S, path, res):
            if S == '':
                res.append(path)
                return 

            for i in range(len(S)):
                cur = S[i]
                backtrack(S[:i] + S[i+1:], path + cur, res)
                
        backtrack(S, path, res)

        return res

```