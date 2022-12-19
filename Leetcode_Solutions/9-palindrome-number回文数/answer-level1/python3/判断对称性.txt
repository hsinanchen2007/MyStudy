### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        num_list = []
        while x > 0:
            m, n = divmod(x, 10)
            num_list.append(n)
            x = m
        for i in range(round(len(num_list) / 2)):
            if num_list[i] != num_list[len(num_list)-1-i]:
                return False
        return True
```