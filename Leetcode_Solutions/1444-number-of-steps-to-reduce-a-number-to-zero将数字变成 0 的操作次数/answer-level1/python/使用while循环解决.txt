### 解题思路
**执行用时 :40 ms, 在所有 Python3 提交中击败了39.80%的用户
内存消耗 :13.5 MB, 在所有 Python3 提交中击败了100.00%的用户**

直接用循环
### 代码

```python3
class Solution:
    def numberOfSteps (self, num: int) -> int:
        a = 0
        while num != 0:
            if num % 2 == 0:
                num = num / 2
            else:
                num = num - 1
            a += 1
        return a
```