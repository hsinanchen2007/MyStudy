### 解题思路
使用字典存储每个数字出现的次数；
将字典value按从大到小排序；
每次删除出现次数最多的数字，集合是最小的。
### 代码

```python3
class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        arrToDic = {}
        for f in arr:
            if f in arrToDic:
                arrToDic[f] += 1
            else:
                arrToDic[f] = 1
        tmp = 0
        res = 0
        for k in sorted(arrToDic, key = arrToDic.__getitem__, reverse = True):
            tmp += arrToDic[k]
            res += 1
            if tmp >= len(arr)/2:
                break
        return res
```