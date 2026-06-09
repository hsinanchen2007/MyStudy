### 解题思路
遍历，直到遍历一个切片是s的一个整数因子，返回TRUE

### 代码

```python3
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        for i in range(1,len(s)):
            if s[:i]*(len(s)//i)==s:
                return True
        return False

```