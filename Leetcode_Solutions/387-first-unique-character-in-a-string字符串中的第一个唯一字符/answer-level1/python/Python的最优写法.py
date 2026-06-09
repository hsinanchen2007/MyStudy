### 解题思路
1.证明字母只出现了一次 
如果一个字符串中的字符在字符串中从左边搜索和从右边搜索得到的index一样，那就证明只有一个了
2.循环每次是从第一个开始的，保证了执行的顺序

### 代码

```python
class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        for c in s:
            if s.find(c) == s.rfind(c):
                return s.find(c)
        return -1
```