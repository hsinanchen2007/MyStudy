### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: List[int]
        """
        arr2set={i:arr2[i] for i in range(len(arr2))}
        res1=[i for i in arr1 if i in arr2]
        res2=[i for i in arr1 if i not in arr2]
        res1set={i:res1.count(i) for i in res1}
        return [ arr2set[i] for i in range(len(set(arr2))) for j in range(res1set.get(arr2set[i],0))] +sorted(res2)
```