```python
def containsNearbyDuplicate(nums, k):
    # 题目中差值最大为k, 意思是只要小于等于k则为True, 而不是所有差值的最大值小于等于k
    # 将相同值的索引存储起来
    import collections
    d = collections.defaultdict(list)
    for i, v in enumerate(nums):
        d[v].append(i)
    
    # 对索引值进行差值的判断, 小于等于k, 则返回True
    for v in d.values():
        for i in range(len(v) - 1):
            if v[i + 1] - v[i] <= k:
                return True
    
    return False

print(containsNearbyDuplicate([1,2,3,1], 3))
print(containsNearbyDuplicate([1,0,1,1], 1))
print(containsNearbyDuplicate([1,2,3,1,2,3], 2))
```