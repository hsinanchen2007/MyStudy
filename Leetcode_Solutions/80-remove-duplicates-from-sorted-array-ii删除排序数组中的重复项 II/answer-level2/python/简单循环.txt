### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def removeDuplicates(self,l):
        i=0
        while i<len(l)-2:
            if l[i+2]==l[i]:
                del l[i+2]
            else:i+=1
        return len(l)

```