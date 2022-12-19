第n次在第n-1的基础上增加一对括号
把所有的情况加入一个新的集合（去重）
```
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        a=['()']
        for i in range(n-1):
            b=set()
            j=0
            for item in a:
                for j in range(len(item)):
                    b.add(item[0:j]+'()'+item[j:len(item)])
            a=list(b)
        return a
```
