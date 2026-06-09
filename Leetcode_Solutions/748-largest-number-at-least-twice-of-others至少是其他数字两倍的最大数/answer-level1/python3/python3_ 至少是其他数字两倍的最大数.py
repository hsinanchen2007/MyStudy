```python
def dominantIndex(nums):
    max_num = max(nums)
    t = len(list(filter(lambda a: a * 2 > max_num, nums))) == 1
    return nums.index(max_num) if t else -1

print(dominantIndex([3,6,1,0]))
print(dominantIndex([1,2,3,4]))
```