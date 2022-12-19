```python
import math
def thirdMax(nums):
    # 因为时间复杂度为O(N), 所以只能一一判断
    r = [float("-inf"), float("-inf"), float("-inf")]
    for n in nums:
        # 重复的值, 无需判断
        if n in r:
            continue
        # 出现最大的值
        if n > r[0]:
            r = [n, r[0], r[1]]
        # 出现第二大的值
        elif n > r[1]:
            r = [r[0], n, r[1]]
        # 出现第三大的值
        elif n > r[2]:
            r[2] = n
    
    return r[0] if math.isinf(r[2]) else r[2]

print(thirdMax([3,2,1]))
print(thirdMax([1,2]))
print(thirdMax([2,2,3,1]))
```