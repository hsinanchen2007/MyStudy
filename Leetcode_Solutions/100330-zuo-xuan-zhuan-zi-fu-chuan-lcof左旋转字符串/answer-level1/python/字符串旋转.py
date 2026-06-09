### 解题思路
第一个方法是用空间换时间，旋转之后的字符串必然是旋转之前的字符串的两倍的从k开始的子串，所以可以直接去slicing
第二个方法利用模运算降低空间复杂度，但需要注意虽然这个方法时间复杂度也是n，但因为每次遍历都需要求模，所以时间实际上耗时更多

### 代码

```python
class Solution(object):
    def reverseLeftWords(self, s, k):
        """
        :type s: str
        :type n: int
        :rtype: str
        """
        n = len(s)
        s = s + s
        return s[k:n + k]

class Solution:
    def reverseLeftWords(self, s: str, k: int) -> str:
        n = len(s)
        res = ''
        for i in range(k, k + n):
            res += s[i % n]
        return res

```