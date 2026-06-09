### 解题思路
上n级台阶的方法 = n-1的方法 + n-2的方法

### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        climb = {}
        
        climb[0] = 0
        climb[1] = 1
        climb[2] = 2
        
        for i in range(3,n+1):
            climb[i] = climb[i-1] + climb[i-2]
        return climb[n]
```