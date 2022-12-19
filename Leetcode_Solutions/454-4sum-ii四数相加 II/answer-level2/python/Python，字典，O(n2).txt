用一个字典记录A+B中所有可能的结果及相应个数
而后遍历C+D所有结果，若0-（C+D）在A+B的字典中，则结果数加上A+B中相应的个数

![image.png](https://pic.leetcode-cn.com/bb63c9e0ea7d7af723ac2fc668d449b6905354b5ccd1159d83db54aec227d2d1-image.png)


```python []
class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        ans = 0
        mapAB = {}
        for i in range(len(A)):
            for j in range(len(A)):
                s = A[i]+B[j]
                mapAB[s] = 1 if s not in mapAB else mapAB[s] + 1

        for i in range(len(A)):
            for j in range(len(A)):
                s = C[i]+D[j]
                if 0-s in mapAB:
                    ans += mapAB[0-s]
        
        return ans

```

