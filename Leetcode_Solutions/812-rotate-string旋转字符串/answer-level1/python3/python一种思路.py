使用切片法，不管字符串怎么变化，两个字符串一定是有两个部分是重合的，只要找出重合的这两个部分，即可得出A可以通过旋转得到B

```
class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        if len(A) != len(B):  #排除字符串相等和不同长度的情况
            return False
        if A == B:
            return True
        for i in range(len(A)):
            if A[:i] in B and A[i:] in B:
                return True

        return False
```
