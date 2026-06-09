由题目描述的泰波那契序列定义直接翻译代码题解

```python
   def tribonacci(self, n):
        """
        :type n: int
        :rtype: int
        """
        T = [0, 1, 1]
        if n < 3:
            return T[n]
        for i in range(3, n + 1):
            #泰波那契序列 Tn 定义Tn+3 = Tn + Tn+1 + Tn+2
            T = [T[1], T[2], sum(T)]
        return T[-1]
```
