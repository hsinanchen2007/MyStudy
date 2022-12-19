### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def kWeakestRows(self, mat, k):
        """
        :type mat: List[List[int]]
        :type k: int
        :rtype: List[int]
        """
        list = []
        for i in range(len(mat)):
            list.append([i,sum(mat[i])])
        #开始排序
    
        relist = []
        for i in range(len(list)):
            list_min = list[0]
            for j in range(len(list)):
                 if list_min[1]>list[j][1]:
                    list_min = list[j]
            list.remove(list_min)
            relist.append(list_min[0])
        return relist[0:k]
```