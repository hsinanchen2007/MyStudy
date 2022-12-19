### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        """
        如果是负数，则返回false
        如果是整数，则取反：
            取反的逻辑很简单，反= 反*10 + 末位数
        """
        if x < 0:
            return False
        cur = 0
        num = x
        while(num != 0):
            cur = cur * 10 + num % 10
            num = num // 10
        return cur == x
```