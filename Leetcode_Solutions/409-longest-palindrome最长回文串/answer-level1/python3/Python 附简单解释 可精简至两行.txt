
#### 说明：
1. 题设求回文串最长长度，因此求解过程可忽略具体字符值。
2. 根据回文串对称特性，可知回文字符串中每个字母个数必为偶数个
3. 同时，可能存在一个中点，值为任意字母
#### 效率：
> Runtime: 12 ms, faster than 98.76% of Python online submissions for Longest Palindrome.
> Memory Usage: 11.7 MB, less than 72.13% of Python online submissions for Longest Palindrome.
#### 复杂度分析（参考自官方题解）：
 - 时间复杂度：$O(N)$
   N为`s`的长度，至少遍历每个字符一次
 - 空间复杂度：$O(1)$
   我们需要开辟额外空间来计数，其大小为`s`中字母的个数，我们都知道字母最多为26个。
#### 代码：
```Python
from collections import Counter


class Solution(object):

    def longestPalindrome(self, s: str) -> int:
        counter = Counter(s)    # 字符计数集

        # 累加每个字符个数的最大偶数，最终结果为回文串最大长度
        palindrome_length = sum(count >> 1 << 1 for count in counter.values())

        # 是否存在任意字符个数为奇数个；如果存在，则需要增一到回文串最大长度上
        add_odd = 1 if any(count & 1 for count in counter.values()) else 0

        # 返回回文串最大长度
        return palindrome_length + add_odd

```
#### 核心代码精简至两行：
```Python
class Solution(object):
    def longestPalindrome(self, s: str) -> int:
        counter = {c: s.count(c) for c in set(s)}    # 字符计数集
        return sum(count >> 1 << 1 for count in counter.values()) + \
               (1 if any(count & 1 for count in counter.values()) else 0)
```