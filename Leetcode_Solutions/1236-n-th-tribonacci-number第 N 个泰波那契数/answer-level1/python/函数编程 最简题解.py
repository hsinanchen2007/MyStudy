
```python
    def tribonacci(self, n):
        """
        :type n: int
        :rtype: int
        """
        from functools import reduce
        T = [0, 1, 1]
        if n < 3:
            return T[n]
        return reduce((lambda t, y: [t[1], t[2], sum(t)]), range(3, n + 1),T)[-1]
        # 等价于
        # for i in range(3, n + 1):
        #     泰波那契序列 Tn 定义Tn+3 = Tn + Tn+1 + Tn+2
        #     T = [T[1], T[2], sum(T)]
        # return T[-1]

```
