```
class Solution(object):
    def getRow(self, rowIndex):
        ans = [1]
        for i in range(rowIndex):
            ans += [1]
            for j in range(i, 0, -1):
                ans[j] = ans[j] + ans[j-1]
        return ans
```
