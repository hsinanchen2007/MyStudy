### 解题思路
这一题实际上是编辑距离题的简化版。

原始版的 [72. 编辑距离题](https://leetcode-cn.com/problems/edit-distance/) 需要使用 DP 求解。
注意到当两个字符串相差 1， 删去一个字符和补充一个字符是等价的。
写代码需要小心，不要导致 bug.

### 代码

```python3
class Solution:
    def oneEditAway(self, first: str, second: str) -> bool:
        n1, n2 = len(first), len(second)
        if n1 < n2:
            first, second = second, first
            n1, n2 = n2, n1
        if n1 - n2 >= 2:
            return False
        if n1 - n2 == 0:
            v = 0
            for i in range(n1):
                if first[i] != second[i]:
                    v += 1
                    if v == 2:
                        return False
            return True  # 忘了这一句导致 bug

        else:  # n1 - n2 == 1
            i, j = 0, 0
            while i<n1 and j < n2:
                if first[i] != second[j]:
                    break
                i += 1
                j += 1
            return first[i+1:] == second[j:]


```