### 解题思路
用Catalan数, 即递推公式为f(n)=f(n-1)f(0)+f(n-2)f(1)+……….+f(1)f(n-2)+f(0)f(n-1)
但和给定n生成二叉树不同的是 对于括号生成 f(n-1)\*f(1) 和 f(1)\*f(n-1) 其实是相等的 因为对称性. 所以生成过程会有重复. 所以以'()'为最小单元用catalan数其实是不合适的.
应该以'(',')'为最小单元去生成, 同时保证'('的数量一定大于等于')'

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def solve(n):
            if n==0:
                return ['']
            if n in mark:
                return mark[n]
            res = set()
            for i in range(1, n): f(n) = f(n-1)*f(1)+f(n-2)*f(2)+...+f(1)*f(n-1), 这里f是集合,所以*是笛卡尔积
                tmp = []
                for left in self.generateParenthesis(n-i):
                    for right in self.generateParenthesis(i):
                        tmp.append(left+right)
                    if i==1: #因为是以'()'为最小单位, 所以要补上(solve(n-1))这种情况, 比如'(()())'
                        tmp.append('('+left+')')
                for t in tmp: # 避免重复, 因为会生成多个'()()..()()'
                    if t not in res: res.add(t)
            mark[n] = res
            # res += ['('*n+')'*n]   
            return res
        mark = {1: ['()']}
        return list(solve(n))
```

```
class Solution:
    def generateParenthesis(self, n: int):
        F = [0] #不能只用一个f, 每条路要有一个f
        res = ['']
        for _ in range(2*n):
            res1 = res2 = []
            f1 = []
            for f in F:
                if f<n:
                    res1 = [s+'(' for i,s in enumerate(res) if F[i]<n]
                    f1 += [f+1]
            for f in F:            
                if f>0:
                    res2 = [s+')' for i,s in enumerate(res) if F[i]>0]
                    f1 += [f-1]
            res = res1 + res2
            F = f1
            print(res, F)
        index = [i for i,v in enumerate(F) if v==0]
        res = [v for i,v in enumerate(res) if i in index]
        print(index)
        return res
s = Solution()
s.generateParenthesis(8)
```
超时, 因为是穷举, 当8对时就要计算2^16种情况, 

深度优先遍历值得学习, 画图知道要生成的是一棵树, 所以直接按条件一步步生成树的结点, 最后将子节点加入res:
```
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if not n:
            return None
        res = []

        def dfs(s, l, r, res):
            if l==n and r==n:
                res.append(s)
                return
            if r>l:
                return
            if l<n:
                dfs(s+'(', l+1, r, res)
            if r<n:
                dfs(s+')', l, r+1, res)
        dfs('', 0, 0, res)
        return res
```
这里l,r代表用了几个左/右括号, 还可以更改成还剩几个左右括号可用, 判断条件改成if r, if l