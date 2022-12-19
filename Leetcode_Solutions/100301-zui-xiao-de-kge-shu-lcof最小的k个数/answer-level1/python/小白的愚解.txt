### 解题思路
使用

### 代码

```python
class Solution(object):
    def getLeastNumbers(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        #存放最小k个数
        res = []
        #给列表排序
        sort_arr = sorted(arr)

        for i in range(0, k):
            res.append(sort_arr[i])
            
        return res
```