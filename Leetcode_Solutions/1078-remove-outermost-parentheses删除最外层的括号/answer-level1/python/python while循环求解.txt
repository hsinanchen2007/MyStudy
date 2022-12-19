### 解题思路
跟栈的思想差不多，统计左右括号的数量，当左右括号数量相等时，去除首尾括号，并将左右括号置零，如此反复循环将字符串相加便求解出来了。

### 代码

```python
class Solution(object):
    def removeOuterParentheses(self, S):
        """
        :type S: str
        :rtype: str
        """
        i=0
        lnum=0
        rnum=0
        m=''
        while i<len(S):
            if S[i] == '(':
                lnum+=1
            if S[i] == ')':
                rnum+=1
            if lnum == rnum:
                k=S[i-lnum-rnum+2:i]
                m=m+k
                lnum=0
                rnum=0
            i+=1
        return m


```