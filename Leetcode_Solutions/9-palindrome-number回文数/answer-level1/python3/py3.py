### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        for i in range(len(str(x))//2):
            if str(x)[i] != str(x)[-(i+1)]:
                break
        else:
            return True
        return False

```