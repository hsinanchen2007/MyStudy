### 代码

```python
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = s.strip()
        vs = s.split(' ')
        #print(vs)
        vs = [word for word in vs if word != '']
        vs.reverse()
        return ' '.join(vs)
```