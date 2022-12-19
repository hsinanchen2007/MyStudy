### 解题思路
这里我使用的不是递归，而是迭代。
递归代价太高。

此题目，主要要写好一般情形就好。

### 代码

```python3
class Solution:
    def tribonacci(self, n: int) -> int:
        if n==0:
            return 0
        if n==1:
            return 1
        if n==2:
            return 1
        f0, f1, f2 = 0, 1, 1
        for i in range(3, n+1):
            f3 = f0 + f1 + f2
            f0, f1, f2 = f1, f2, f3
        return f3
            
```