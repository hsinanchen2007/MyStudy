### 解题思路
关键在于找到行变换的特点：从0依次递增至numRows-1再递减至0，所以想到用一个flag作为标记

### 代码

```python
class Solution(object):
    def convert(self, s, numRows):
        if numRows == 1:
            return s
        ans = ['' for _ in range(numRows)]
        flag = -1
        i = 0
        for c in s:
            if i == 0 or i == numRows - 1:
                flag = -flag
            ans[i] += c
            i += flag
        return str("".join(ans))

```