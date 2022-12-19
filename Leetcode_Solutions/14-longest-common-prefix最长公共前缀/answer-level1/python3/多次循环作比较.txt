### 解题思路
有时一个暴力解法，多次循环作比较

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if strs == []:
            return ''
        else:
            num1 = -1
            num2 = 0
            min1 = len(strs[0])
            for i in strs:
                if len(i) <= min1:
                    min1 = len(i)
            for i in range(min1):
                for j in strs:
                    s = strs[0][i]
                    if s == j[i]:
                        continue
                    else:
                        num2 = -1
                        break
                if num2 == -1:
                    break
                else:
                    num1 = num1 + 1
            if num1 == -1:
                return ''
            else:
                return strs[0][0: num1 + 1]
```