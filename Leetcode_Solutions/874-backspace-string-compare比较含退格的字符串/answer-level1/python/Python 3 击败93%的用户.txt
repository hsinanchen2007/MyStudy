### 解题思路
28ms,13.6MB
哇哇哇，又击败了这么多Python3用户，leetcode会不会是骗我的？……
挺简单的啊……
有一点需要提一下，`#a`这种情况的#是不做任何处理的，所以直接忽略就可以了。

### 代码

```python3
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        stack_s,stack_t=[],[]
        for i in S:
            if i =='#':#非空才能pop
                if stack_s:
                    stack_s.pop()
            else:
                stack_s.append(i)
        
        for i in T:
            if i=='#' :
                if stack_t: 
                    stack_t.pop()
            else:
                stack_t.append(i)
        return(stack_s==stack_t)

```