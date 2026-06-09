### 解题思路
转 str ，使用 [::-1] 反转字符串

### 代码

```python
class Solution:
    def isPalindrome(self, x: int) -> bool:
        return str(x) == str(x)[::-1]
```