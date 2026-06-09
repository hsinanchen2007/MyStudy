### 思路

**字符串**

```
统计字符串中各个字符个数。
最后尽可能多地输出偶数个相同字符。
```

##### Python3代码

```python
class Solution:
    def longestPalindrome(self, s: str) -> int:
        import collections
        # 统计各字符个数
        count = collections.Counter(s).values()
        sum = 0
        for x in count:
            if x // 2 > 0:
                # 取偶数个字符
                sum += x // 2 * 2
        if sum == len(s):
            return sum
        else:
            return sum + 1
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/0409-Longest-Palindrome/0409.py)