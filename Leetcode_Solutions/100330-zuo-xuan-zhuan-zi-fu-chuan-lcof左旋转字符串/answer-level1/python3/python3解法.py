### 解题思路
其实我想的可能过于简单了，把字符串的下标找到，然后依据下标将字符串截取为两部分，按照反序加在一起就可以了。

这是在leetcode上面解答的第一道题，花了2小时36分钟，而且是借鉴了大佬们的思路和思想，但是我坚持下来了，万事开头难，加油。

### 代码
```python3
class Solution:
      def reverseLeftWords(self, s: str, n: int):
          return s[n:]+s[:n]
```