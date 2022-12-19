### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        s_cnt = collections.Counter(s)
        # signal = 0
        ans = 0
        for i in s_cnt.values():
            ans += i//2*2
            if ans%2==0 and i%2==1:
                ans+=1

        return ans

```