### 解题思路
先转类型，再用切片逆序判等

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        x=str(x)
        if(x==x[::-1]):
            return True
        else:
            return False
```