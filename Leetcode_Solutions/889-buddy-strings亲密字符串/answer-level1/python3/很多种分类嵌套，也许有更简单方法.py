一开始代码是有20行左右，以为自己想得很周全了，结果一点点加条件，变成了这个样子。
耗时还行，内存占太多

执行用时 :
32 ms
, 在所有 Python3 提交中击败了
86.98%
的用户
内存消耗 :
13.5 MB
, 在所有 Python3 提交中击败了
25.58%
的用户



```
class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if len(A) != len(B):
            print('jugdge1')
            return False
        else:
            find_first = False
            find_second = False
            a = None
            b = None
            for i in range(len(A)):
                if find_first:
                    if not find_second:
                        if A[i] != B[i]:
                            if not (A[i] == b and B[i] == a):
                                print('jugdge2')
                                return False
                            else:
                                find_second = True
                                continue
                    else:
                        if A[i] != B[i]:
                            print('jugdge3')
                            return False
                else:
                    if A[i] != B[i]:
                        a = A[i]
                        b = B[i]
                        find_first = True
                
```
