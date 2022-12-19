### 解题思路
利用集合set判断邮箱数目

### 代码

```python3
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        temp = set()
        for i in emails:
            temp.add(tuple(i.split('@')))
        ret = set()
        for i in temp:
            val, col = '', i[1]
            for j in range(len(i[0])):
                if i[0][j] != '.' and i[0][j] != '+':
                    val += i[0][j]
                elif i[0][j] == '.':
                    pass
                elif i[0][j] == '+':
                    break
            ret.add(tuple((val, col)))
        return len(ret)
```