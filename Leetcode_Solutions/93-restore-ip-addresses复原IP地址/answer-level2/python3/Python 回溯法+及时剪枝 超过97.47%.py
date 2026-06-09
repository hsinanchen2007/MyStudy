### 解题思路
回溯法+及时剪枝

### 代码

```python3
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:

        res = []

        def helper(prev, residue):
            if len(prev) == 4 and not residue:
                curr = ""
                for i in range(4):
                    curr += prev[i] + "."
                res.append(curr[:-1])

            if not residue:
                return
            if len(residue) > (4 - len(prev)) * 3:
                return
            if len(residue) < 4 - len(prev):
                return
            
            for i in range(min(3, len(residue))):
                if int(residue[0 : i + 1]) <= 255 and str(int(residue[0 : i + 1])) == residue[0 : i + 1]:
                    curr = prev[:]
                    curr.append(residue[0 : i + 1])
                    helper(curr, residue[i + 1: len(residue)])
        
        helper([], s)

        return  res
            
```