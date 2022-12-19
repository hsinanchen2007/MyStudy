### 解题思路
空栈或者与第一个字符相同的情况入栈。继续下一个字符
如果当前字符与第一个字符不同，那么就出栈，直到空栈为平衡字符串

### 代码

```python3
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        result, items = 0, []
        for c in s:           
            if not items or c == items[0]:
                items.append(c)
                continue

            items.pop()
            if not items:
                result += 1

        return result
```