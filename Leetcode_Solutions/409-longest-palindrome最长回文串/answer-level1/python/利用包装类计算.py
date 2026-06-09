### 解题思路
利用Counter计算重复字符，从而得到最长回文串长度

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        from collections import Counter
        map_ = Counter(s)
        flag = sum_ = 0
        for count in map_.values():
            a, b = divmod(count, 2)
            if b == 1 and flag == 0:
                flag, sum_ = 1, sum_ + 1
            sum_ += a * 2
        return sum_

            

```