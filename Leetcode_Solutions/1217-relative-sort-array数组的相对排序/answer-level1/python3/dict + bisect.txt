执行用时 : 44 ms, 在所有 Python3 提交中击败了98.48%的用户

内存消耗 :13.8 MB, 在所有 Python3 提交中击败了100.00% 的用户
```python
class Solution:
    def relativeSortArray(self, arr1, arr2):
        from collections import defaultdict
        from bisect import insort_left
        arr2_dict = set(arr2)

        result = []
        result_not_in_arr2 = []
        arr1_dict = defaultdict(int)
        for i in arr1:
            if i in arr2_dict:
                arr1_dict[i] += 1
            else:
                insort_left(result_not_in_arr2, i)

        for i in arr2:
            if i in arr1_dict:
                result.extend([i]*arr1_dict[i])
        result.extend(result_not_in_arr2)
        return result
```
