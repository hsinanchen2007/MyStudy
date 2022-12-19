### 解题思路
一开始是先查找“[” 就用了递归从外“[]”执行到内，但是题目提交不通过；
改成查找“]”,由内到外一次替换文本。

### 代码

```python
class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        while (s.count('[')!=0):
            for i,x in enumerate(s):
                if x ==']':
                    k = s[:i].rfind('[')
                    j =0
                    while(not s[j:k].isdigit()):
                        j=j+1
                    t = int(s[j:k])    
                    s =s[:j]+t*s[k+1:i]+s[i+1:]
                    break
        return s


```