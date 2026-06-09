### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def compressString(self, S):
        """
        :type S: str
        :rtype: str
        """
        res = ''
        if len(S)<1:return ''
        chang,k,d = len(S),1,0
        while chang-d-1>0:

            if d+1<chang and S[d] == S[d+1]:
                k+=1
            else:
                res+=S[d]+str(k)
                k=1
            d+=1
        res+= S[d] + str(k)
        if len(res)>=chang:
            return S
        else:
            return res
```