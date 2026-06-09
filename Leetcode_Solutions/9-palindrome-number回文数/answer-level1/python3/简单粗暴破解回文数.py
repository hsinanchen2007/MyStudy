
核心思路，取反；
    先将int类型转换成string类型，然后将其反向切片，看是否和x相等，如果相等返回true，繁殖返回false
### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        return str(x)[::-1] == str(x)

```