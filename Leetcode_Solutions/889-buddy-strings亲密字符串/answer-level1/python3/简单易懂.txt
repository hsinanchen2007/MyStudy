如果相等且有重复则true
若A B含有内容是一样的，只是顺序不同，则进行比较，若只有两个位置的内容不同，则返回true
```
def buddyStrings(self, A: str, B: str) -> bool:
    if A == B and len(set(A)) < len(A):
        return True
    a = 0
    if sorted(A) == sorted(B):
        for i in range(len(A)):
            if A[i] != B[i]:
                a += 1
        if a == 2:
            return True
        else:
            return False
    return False
```
