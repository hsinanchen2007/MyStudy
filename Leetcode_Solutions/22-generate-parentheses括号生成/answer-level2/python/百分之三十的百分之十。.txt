### 解题思路
典型的回溯法，按dfs的思路写，判断当前路径是否合法，若不合法则直接return，不添加任何东西

说起来大家都用的什么方法怎么空间消耗都比我小。。。


### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        self.ans=[]
        self.temp=[]
        def dfs(n,leftnum,rightnum):
            if leftnum==n and rightnum==n:
                self.ans.append(''.join(self.temp))
            if rightnum>leftnum:
                return
            if 2*n-(leftnum+rightnum)<leftnum-rightnum:
                return
            self.temp.append('(')
            dfs(n,leftnum+1,rightnum)
            self.temp.pop()
            self.temp.append(')')
            dfs(n,leftnum,rightnum+1)
            self.temp.pop()
        dfs(n,0,0)
        return self.ans
            #两种情况不继续发展一个是右括号数量更多了，二个是剩下的数目不够右括号填左括号了


```