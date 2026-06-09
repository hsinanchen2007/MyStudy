### 解题思路
主要考察的是分治和递归的思想，可以先从简单的例子入手

### 代码

```python
class Solution(object):
    def hanota(self, A, B, C):
        n = len(A)
        self.move(n,A,B,C)
    #先从简单的入手，例如2个盘子
    def move(self,n,A,B,C):
        #若n=1则直接进行转移，递归到最后必定会有n=1
        if n == 1:
            C.append(A[-1])
            A.pop()
            return
        else:
            #A通过C转移到B
            self.move(n-1,A,C,B)
            C.append(A[-1])
            A.pop()
            #B通过A转移到C
            self.move(n-1,B,A,C)


        
```