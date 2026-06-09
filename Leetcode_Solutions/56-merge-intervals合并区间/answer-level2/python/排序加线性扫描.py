### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def merge(self,l):
        l.sort(key=lambda i:i[0])
        i=0
        while i<len(l)-1:
            if l[i][1]>=l[i+1][0]:
                l[i:i+2]=[[l[i][0],max(l[i][1],l[i+1][1])]]
            else:
                i+=1
        return l

```