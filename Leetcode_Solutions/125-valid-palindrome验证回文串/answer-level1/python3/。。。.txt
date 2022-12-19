### 解题思路
用一个额外的list

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        temp = []
        j = 0
        for elem in s:
            if 'A' <= elem <= 'Z':
                temp.append(chr(ord(elem)+32))
            if 'a' <= elem <= 'z' or '0' <= elem <= '9':
                temp.append(elem)
        size = len(temp) - 1
        i = size
        while j <= size // 2:
            if temp[j] == temp[i]:
                j += 1
                i -= 1
            else:
                return False
        return True

        
        
```