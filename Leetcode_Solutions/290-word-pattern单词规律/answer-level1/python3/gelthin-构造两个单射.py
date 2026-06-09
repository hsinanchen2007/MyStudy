### 解题思路
这里参照习题[205. 同构字符串](https://leetcode-cn.com/problems/isomorphic-strings/)的解法一，构造一个单射判断函数，然后判断两次。



### 代码

```python3
class Solution:
    

    def wordPattern(self, pattern: str, str: str) -> bool:
        def isInjection(A, B):  # 单射
            D = dict()
            n = len(A)
            for i in range(n):
                if A[i] in D:
                    if D[A[i]] != B[i]:
                        return False
                else: # A[i] not in D
                    D[A[i]] = B[i]
            return True
        
        l_p = [x for x in pattern]
        l_s = str.split()
        if len(l_p) != len(l_s):
            return False
        return isInjection(l_p, l_s) and isInjection(l_s, l_p)

            
```