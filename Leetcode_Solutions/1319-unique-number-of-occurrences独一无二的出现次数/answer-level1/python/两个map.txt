### 解题思路
此处撰写解题思路
two map
### 代码

```python
class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        a = {}
        for i in arr:
            if i not in a.keys():
                a[i] = 1
            else:
                a[i] += 1

        b = {}
        for j in a.values():
            if j not in b.keys():
                b[j] = 1
            else:
                return False
        
        return True
```