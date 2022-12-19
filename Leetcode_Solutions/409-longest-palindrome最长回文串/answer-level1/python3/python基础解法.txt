### 解题思路
当一个数出现偶次数的时候直接添加，ans = v // 2 * 2,当某个数第一次出现奇数次的时候，我们可以加上ans + 1作为中心点

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        ans = 0
        count = collections.Counter(s)
        for v in count.values():
            ans += v // 2 * 2
            if ans % 2 == 0 and v % 2 == 1:
                ans += 1
        return ans
```