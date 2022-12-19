### 解题思路
40ms,13.7MB。第一次击败85%的Python用户……
哈哈哈，是不是太简单了没人做……
就是一个栈，都没什么好讲的。

### 代码

```python3
class Solution:
    def calPoints(self, ops: List[str]) -> int:
        stack=[]
        for i in ops:
            if i=='C':
                stack.pop()
            elif i=='D':
                stack.append(stack[-1]*2)
            elif i=='+':
                stack.append(stack[-1]+stack[-2])
            else:
                stack.append(int(i))
        return(sum(stack))


```