```javascript []
console.log('Hello world!')
```
```python []
class Solution:

    def longestPalindrome(self, s: str) -> str:

        lenth = len(s)
        if lenth < 2:
            return s

        r_left, r_right = 0, 0
        long_lenth = 0
        dp = [[False for _ in range(lenth)] for _ in range(lenth)]
        
        for right in range(1, lenth):
            for left in range(right):
                if (s[left] == s[right]) and (dp[left+1][right-1] or right <= left+2):
                    dp[left][right] = True
                    if long_lenth < right-left+1:
                        long_lenth = right-left+1
                        r_left, r_right = left, right
        if long_lenth == 0:
            return s[0]
        else:
            return s[r_left:r_left+long_lenth]
```
```ruby []
puts 'Hello world!'
```
