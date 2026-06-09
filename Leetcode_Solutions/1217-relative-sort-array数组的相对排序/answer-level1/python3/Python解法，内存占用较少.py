执行用时 :64 ms, 在所有 Python3 提交中击败了59.00%的用户
内存消耗 :13.9 MB, 在所有 Python3 提交中击败了100.00%的用户
```
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        arr = []
        for i in range(len(arr2)):
            for j in range(arr1.count(arr2[i])):
                arr.append(arr2[i])
                arr1.remove(arr2[i])
        arr.extend(sorted(arr1))
        return arr
```
