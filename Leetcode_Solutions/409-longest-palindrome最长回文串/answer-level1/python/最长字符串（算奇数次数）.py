### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        # ls = collections.Counter(s)
        # res = 0
        # ans = 0
        # for c in ls:
        #     if ls[c]%2==0:
        #         res+=ls[c]
        #     else:
        #         res+=(ls[c]-1)
        #         ans = 1
        # return res+ans
        ls = collections.Counter(s)
        q = 0
        for v in ls.values():
            if v&1:
                q+=1
        return len(s)-q+1 if q else len(s)-q

```