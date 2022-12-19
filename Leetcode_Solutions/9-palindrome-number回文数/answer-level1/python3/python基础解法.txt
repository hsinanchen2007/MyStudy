### 解题思路
1. 将int转成字符串切片即可
2. 双指针判断
3. 取余操作，反转一半判断是否相等

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        return str(x) == str(x)[::-1]
```