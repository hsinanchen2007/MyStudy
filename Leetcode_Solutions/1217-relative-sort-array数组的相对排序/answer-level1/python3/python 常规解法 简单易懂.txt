执行用时 :52 ms, 在所有 Python3 提交中击败了45.37%的用户
内存消耗 :13.6 MB, 在所有 Python3 提交中击败了44.97%的用户

```
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        arr1.sort()
        a = []
        for i in arr2:
            x=arr1.index(i)
            for j in range(x,len(arr1)):
                if arr1[j]!=i:
                    break
                a.append(arr1[j])
        for i in arr1:
            if i not in arr2:
                a.append(i)
        return a
```
