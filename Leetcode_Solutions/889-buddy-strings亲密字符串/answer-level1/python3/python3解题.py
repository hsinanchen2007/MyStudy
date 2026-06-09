### 解题思路
执行用时 :36 ms
内存消耗 :13 MB
方法比较笨，易理解
### 代码

```python3
class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        i = len(A)
        j = len(B)
        a = 0
        b = []
        c = []
        if A == B:
            A = ",".join(A)
            C = A.split(",")
            for y in set(C):
                if C.count(y) >= 2:
                    return True
        else:
            if  i == j:
                for k in range(0, i):
                    if A[k] is not B[k]:
                        a += 1
                        b.append(A[k])
                        c.append(B[k])
                if a == 2 and b[0] == c[1] and c[0] == b[1]:
                    return True
                else:
                    return False
            else:
                return False
```