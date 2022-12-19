### 解题思路
遍历数组，遇0加1遇1加2，若是以1比特结尾，最后i = len(bits)-1，否则，i = len(bits)

### 代码

```python
class Solution(object):
    def isOneBitCharacter(self, bits):
        i = 0
        while i < len(bits) - 1:
            if bits[i] == 0:
                i += 1
            else:
                i += 2
        if i == len(bits):
            return False
        if i == len(bits) - 1:
            return True
```