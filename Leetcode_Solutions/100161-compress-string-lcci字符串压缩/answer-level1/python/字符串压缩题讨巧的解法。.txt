### 解题思路
根据题解用的一种讨巧对做法。将就着看

### 代码

```python
class Solution(object):
    def compressString(self, S):
        """
        :type S: str
        :rtype: str
        """
        li = S+"8"
        item = 0
        KS = ""
        while item <len(li):
            for k in range(item, len(li)):
                if li[item] != li[k]:
                    tmp =  li[item]+"%d"%(k-item)
                    item  = k
                    KS += tmp
            item += 1
        if len(KS) >= len(S):
            return  S
        else:
            return KS
```