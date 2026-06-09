### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        k = s.split()
        ans = ' '.join(k[::-1])
        return ans








```