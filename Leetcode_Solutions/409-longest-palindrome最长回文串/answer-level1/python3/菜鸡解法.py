### 解题思路
暴力硬怼
### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        tempdict = {}
        for i in s:
            if i not in tempdict.keys():
                tempdict.update({i:1})
            else:
                temp = tempdict[i]
                tempdict.update({i:temp+1})
        
        ans = 0
        temp_max = 0
        for i in tempdict.keys():
            if tempdict[i]%2 == 0:
                ans += tempdict[i]               
            else:
                if temp_max == 0:
                    temp_max = tempdict[i]
                else:
                    if temp_max<tempdict[i]:
                        ans += temp_max-1
                        temp_max = tempdict[i]
                    else:
                        ans+=tempdict[i]-1
        ans += temp_max

        return ans
```