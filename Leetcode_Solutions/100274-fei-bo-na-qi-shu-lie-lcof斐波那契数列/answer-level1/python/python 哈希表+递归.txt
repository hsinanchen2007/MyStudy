### 解题思路
用哈希表存计算出来的中间结果，以便后面调用，减少多余的运算

### 代码

```python3
class Solution:
    def fib(self, n: int) -> int:
        self.hashmap = {}
        self.hashmap[0]=0
        self.hashmap[1]=1
        self.mod = 10**9 + 7
        def helper(n):
            if n<2:
                return n
            if n in self.hashmap:
                return self.hashmap[n]
            else:
                result = helper(n-1)+helper(n-2)
                self.hashmap[n]=result
                return result
        return helper(n)%self.mod
```