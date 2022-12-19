### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def isPalindrome(self, x):
        if x < 0:
            return False
        ori = x
        target = 0
        while ori > 0:
            mod = ori % 10
            ori = ori // 10
            target = target * 10 + mod
        return x == target

```