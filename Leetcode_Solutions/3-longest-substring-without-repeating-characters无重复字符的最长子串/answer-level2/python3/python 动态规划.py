```javascript []
console.log('Hello world!')
```
```python []
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        lenth = len(s)
        
        if lenth <= 1:
            return lenth
        
        dp = [1 for _ in s]
        
        for i in range(1, lenth):

            n = lenth -1 - i
            if s[n] not in s[n+1:n+1+dp[n+1]]:
                dp[n] = dp[n+1] + 1
            else:
                dp[n] = 1 + s[n+1:n+1+dp[n+1]].index(s[n])
    
        return max(dp)
```
```ruby []
puts 'Hello world!'
```
