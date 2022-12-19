### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maximum69Number (self, num: int) -> int:
        return int(str(num).replace('6', '9', 1))
```