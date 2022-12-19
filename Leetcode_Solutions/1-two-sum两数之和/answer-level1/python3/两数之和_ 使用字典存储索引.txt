```python []
def twoSum(nums, target):
    # 假设v1 + v2 = target, i1, i2为它们的索引
    d = {}
    for i, v in enumerate(nums):
        # 找到v2, 则通过d, 将v1的索引找出(d[v])
        if v in d:
            return [d[v], i]
        # 将v2和i1关联起来, 这样定位到v2时候, 就可以找到v1的索引i1
        d[target - v] = i
        
print(twoSum([2,7,11,15], 9))
```
