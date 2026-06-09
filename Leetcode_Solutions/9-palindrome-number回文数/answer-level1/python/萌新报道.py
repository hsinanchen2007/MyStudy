### 解题思路
转成字符串，判断左右是否相等

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        xstr=str(x)
        half=len(xstr)//2
        return xstr[:half]==xstr[-1:-half-1:-1]

```