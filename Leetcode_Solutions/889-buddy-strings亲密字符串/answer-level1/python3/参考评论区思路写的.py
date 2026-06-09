    1、字符串长度不相等，直接返回false
    2、字符串长度相等的时候，只要有重复的元素返回true
    3、有不相等的两个地方，查看他们交换后是否相等即可
```
class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if len(A) != len(B):
            return False
        if A==B and len(set(A))<len(A):
            return True
        if A==B and len(set(A))==len(A):
            return False
        start = 0
        end = len(A) - 1
        while start <= end and A[start] == B[start]:
            start += 1
        while start <= end and A[end] == B[end]:
            end -= 1
        A1 = [val for val in A]
        B1 = [val for val in B]
        A1[start], A1[end] = A[end], A[start]
        return A1 == B1

```
