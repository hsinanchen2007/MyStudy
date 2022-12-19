```
class Solution(object):
    def repeatedStringMatch(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: int
        """
        import math
        
        n = int(math.ceil(float(len(B)) / len(A)))
        
        a = A
        A = A * n
        
        if not B in A * 2:
            return -1

        while 1:
            if B in A:
                return n
            A += a
            n += 1
```
先把A扩展到至少比B长，再看B是否在new_A * 2里，不是直接返回-1，是的话用newA+A迭代求n
执行用时 :120 ms, 在所有 python 提交中击败了87.74%的用户
