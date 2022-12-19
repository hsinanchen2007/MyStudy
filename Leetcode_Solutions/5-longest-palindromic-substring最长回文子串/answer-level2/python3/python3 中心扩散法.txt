### 解题思路

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        def check(subS):
            if subS == subS[::-1]:
                return True
        if len(s) == 1 or len(s) == 0:
            return s
        if len(s) == 2:
            if check(s):
                return s
            else:
                return s[0]
        maxS = s[0]
        for i in range(1,len(s)-1):
            left = i - 1
            right = i + 1
            while left >= 0:
                if s[i] == s[left]:
                    left -= 1
                else:
                    break
            while right < len(s):
                if s[i] == s[right]:
                    right += 1
                else:
                    break
            if left >=0 and right < len(s):
                while left >= 0 and right < len(s):
                    if s[left] == s[right]:
                        if left == 0 or right == len(s) - 1:
                            break
                        else:
                            left -= 1
                            right += 1
                    else:
                        left += 1
                        right -= 1
                        break
            else:
                left += 1
                right -= 1
            mid = s[left : right + 1]
            if len(mid) > len(maxS):
                maxS = mid
        return maxS
      
```