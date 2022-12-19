### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution():
    def hanota(self,A,B,C):
        if len(A) == 0:
            pass
        else:
            n = len(A)
            self.disk_move(n,A,B,C)

    def disk_move(self,n,A,B,C):
        if n == 1:
            C.append(A[-1])
            A.pop()
        else:
            self.disk_move(n-1,A,C,B)
            C.append(A[-1])
            A.pop()
            self.disk_move(n-1,B,A,C)


```