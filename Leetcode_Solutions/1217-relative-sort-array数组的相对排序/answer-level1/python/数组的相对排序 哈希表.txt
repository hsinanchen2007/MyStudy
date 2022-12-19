### 解题思路


### 代码

```python
class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        dic = {}
        arr11 = []
        for i,c in enumerate(arr1):
            if c in arr2 :
                if c not in dic:
                    dic[c] = 1
                else:
                    dic[c] += 1
            else:
                arr11.append(c)
        ans = []
        for c in arr2:
            ans += [c]*dic[c]
        ans += sorted(arr11)
        return ans
```