### 解题思路
排序 + 自定义cmp

### 代码

```python
class Solution:
    def minNumber(self, nums): 
        retList=sorted(map(str, nums),cmp=lambda x,y :  cmp(x + y ,y + x) )
        ret = ''.join(retList)
        return ret


```