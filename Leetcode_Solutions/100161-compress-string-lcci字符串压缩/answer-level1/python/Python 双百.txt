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
        origin_str = "0"
        count = 0
        rlist = []
        if len(S)==0:
            return S
        for current_str in S:
            if current_str == origin_str:
                count+=1
            elif count!=0:
                rlist.append(origin_str)
                rlist.append(str(count))
                origin_str = current_str
                count = 1
            else:
                origin_str = current_str
                count = 1
        if count!=0:
            rlist.append(origin_str)
            rlist.append(str(count))
        rstr = "".join(rlist)
        if len(rstr)<len(S):
            return rstr
        else:
            return S
```