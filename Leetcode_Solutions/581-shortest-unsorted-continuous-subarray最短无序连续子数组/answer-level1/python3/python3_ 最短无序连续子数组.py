```python
def findUnsortedSubarray(nums):
    start, end, N = -1, -1, len(nums)
    source_nums = nums[:]
    nums.sort()
    for i in range(N):
        # 这里j之所以不等于N - 1, 是因为"判断2"中已经保证N - 1 - i之后的已经确定过
        j = N - 1 - i
        if start != -1 and end != -1:
            break
        # 判断1
        if start == -1 and source_nums[i] != nums[i]:
            start = i
        # 判断2
        if end == -1 and source_nums[j] != nums[j]:
            end = j + 1
    return end - start

print(findUnsortedSubarray([2, 6, 4, 8, 10, 9, 15]))
```