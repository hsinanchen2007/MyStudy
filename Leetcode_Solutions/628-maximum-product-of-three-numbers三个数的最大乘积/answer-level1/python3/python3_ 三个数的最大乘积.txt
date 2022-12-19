```python
def maximumProduct(nums):
    # 最大三个数, 要么都是正数, 要么是两个负数+一个正数
    nums.sort()
    v1 = nums[-1] * nums[-2] * nums[-3]
    v2 = nums[0] * nums[1] * nums[-1]
    return max(v1, v2)

print(maximumProduct([1,2,3]))
print(maximumProduct([1,2,3,4]))
```