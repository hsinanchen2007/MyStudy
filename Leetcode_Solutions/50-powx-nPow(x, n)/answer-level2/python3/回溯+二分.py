### 解题思路
![8c7f0944673c96be16c87eb45557f8b.png](https://pic.leetcode-cn.com/a18f5ba1035c553893635e525f15eb2eb3e7b54e85a812dc9d8a9ba67986059f-8c7f0944673c96be16c87eb45557f8b.png)

关键点：回溯+二分

### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        flag = False
        if n < 0:
            n = -n
            flag = True

        def dfs(n):
            if n == 1:
                return x
            res = dfs(n//2)
            if n % 2 == 0:
                return res * res
            else:
                return res * res * x
        res = dfs(n)                
        if flag:
            return 1.0/res 
        return res
```