### 解题思路
构建字符列表，比较字符列表是否相等，得到字符串比较结果。超过99.26%用户

### 代码

```python3
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        temp1, temp2 = [], []
        for i in S:
            if i == '#':
                if temp1:
                    temp1.pop()
            else:
                temp1.append(i)
        for i in T:
            if i == '#':
                if temp2:
                    temp2.pop()
            else:
                temp2.append(i)
        if temp1 == temp2:
            return True
        else:
            return False
```