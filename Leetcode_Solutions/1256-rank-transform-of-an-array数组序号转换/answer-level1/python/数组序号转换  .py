### 解题思路
去重、排序、哈希表记录序号，用到zip()
### 代码

```python
class Solution(object):
    def arrayRankTransform(self, arr):
        arr_copy = set(arr)
        arr_copy = sorted(list(arr_copy))
        dic = dict(zip(arr_copy,range(1,len(arr_copy)+1))) #arr1=[1,2,3] arr2=[4,5,6] zip(arr1,arr2) = [(1,4),(2,5),(3,6)] 以元组形式输出的列表
        for i,c in enumerate(arr):
            arr[i] = dic[c]
        return arr
```