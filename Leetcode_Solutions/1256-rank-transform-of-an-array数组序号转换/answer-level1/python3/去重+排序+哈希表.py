### 解题思路
拷贝+去重+排序+哈希表记录索引位置

### 代码

```python3
class Solution:
    def arrayRankTransform(self, arr):
        length = len(arr)
        import copy
        arr1 = list(set(copy.copy(arr)))
        # 要去重，不然序列会是错的
        # 注意在这拷贝就行，不需要深拷贝，谢谢大佬指点
        arr1.sort()
        index_dict = dict(zip(arr1,range(len(arr1))))
        res = []
        for i in range(length):
            res.append(index_dict[arr[i]] + 1)
        return res
```