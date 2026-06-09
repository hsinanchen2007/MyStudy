### 解题思路
统计偶数，然后中心+1

### 代码

```python
class Solution:
    def longestPalindrome(self, s: str) -> int:
        ans = 0
        cnt = collections.Counter(s)
        # 统计偶数
        for key in cnt:
            ans += cnt[key]//2 * 2
        # 中心+1
        if ans < len(s):
            ans = ans+1
        return ans 
        
                
```