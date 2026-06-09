执行用时 : 40 ms, 在所有 Python3 提交中击败了 97.77% 的用户
内存消耗 : 13.8 MB, 在所有 Python3 提交中击败了 100.00% 的用户

思路：
    1. 建立长为 max(arr) - min(arr) 的全0 List count，count[0] 对应 arr 中最小值出现次数，count[-1] 对应 arr 中最大值出现次数；
    2. 遍历arr，对其中每个 item ，在 count 中的对应位置 item - min_arr 加1，记录该值出现次数
    3. 去除 count 中的 0 元素，
    4. 对 List 进行 Set，通过判断长度是否发生改变，判断有无出现相同次数的元素

```
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        max_arr = max(arr)
        min_arr = min(arr)
        count = [0 for _ in range(max_arr - min_arr + 1)]
        for item in arr:
            count[item - min_arr] += 1
        nonZero_count = [i for i in count if i != 0]
        return len(nonZero_count) == len(set(nonZero_count))
```

