
每次匹配都是先找到值最大的那个数组的编号，然后让值较小的那些数组右移指针去适应。
```python
class Solution:
    def arraysIntersection(self, arr1, arr2, arr3):
        idxs = [0, 0, 0]
        arrs = (arr1, arr2, arr3)
        res  = []
        while idxs[0] < len(arr1) and idxs[1] < len(arr2) and idxs[2] < len(arr3):
            if arr1[idxs[0]] == arr2[idxs[1]] == arr3[idxs[2]]:
                res.append(arr1[idxs[0]])
                for i in range(3):
                    idxs[i] += 1
                continue
            # 计算 argmax_i arrs[i][idxs[i]]
            maxidx = 0
            if arr1[idxs[0]] < arr2[idxs[1]]:
                maxidx = 1
            if arrs[maxidx][idxs[maxidx]] < arr3[idxs[2]]:
                maxidx = 2
            # 值较小的数组的指针后移，以尝试与值最大的数组匹配
            for i in range(2):
                i = (maxidx + i + 1) % 3
                while arrs[i][idxs[i]] < arrs[maxidx][idxs[maxidx]]:
                    idxs[i] += 1
                    if idxs[i] == len(arrs[i]):
                        return res
        return res
```
