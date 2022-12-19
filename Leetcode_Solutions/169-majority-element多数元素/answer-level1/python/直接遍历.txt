### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def majorityElement(self, n):
        n.sort()
        r=[0]
        for i in range(len(n)):
            if i>0 and n[i]!=n[i-1]:
                if i-r[-1]>len(n)/2:return n[i-1]
        return n[-1]
```