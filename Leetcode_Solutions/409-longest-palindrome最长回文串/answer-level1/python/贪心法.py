执行用时 :28 ms, 在所有 Python3 提交中击败了98.70%的用户
内存消耗 :13.5 MB, 在所有 Python3 提交中击败了8.14%的用户
### 代码

```python3
import collections
class Solution:
    def longestPalindrome(self, s: str) -> int:
        ans=0
        count=collections.Counter(s)
        for v in count.values():
            ans+=v//2*2
            if v%2==1 and ans%2==0:
                ans+=1
        return ans
```