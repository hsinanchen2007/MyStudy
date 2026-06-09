### 解题思路
用counter计数，然后直接往两边增加相同的数字，如果此时序列为偶数的话，可以添加一个单独的字符作为回文中心

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        ans = 0
        count = collections.Counter(s)
        for num in count.values():
            ans += num//2 * 2
            if ans%2 == 0 and num%2 ==  1:
                ans += 1
                
        return ans 
```