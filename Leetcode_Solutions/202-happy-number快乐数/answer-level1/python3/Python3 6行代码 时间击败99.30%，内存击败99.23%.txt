### 解题思路
根据题目意思直接写出代码
两种情况：
1. 求和等于1 -> return True
2. 进入循环，且循环中没有1 -> return False

### 代码

```python3
class Solution:
    def isHappy(self, n: int) -> bool:
        seen = []
        while n not in seen:
            if n==1:return True
            seen.append(n)
            n = sum([int(i)*int(i) for i in str(n)])
        return False