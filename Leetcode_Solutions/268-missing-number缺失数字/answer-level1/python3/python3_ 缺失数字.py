```python
def missingNumber(nums):
    # 对数组进行排序
    nums.sort()
    # 让数组的值跟索引一一匹配, 不匹配上则为缺失的数字
    for i in range(len(nums)):
        if nums[i] != i:
            return i
    # 如果全部都不匹配, 则说明缺失的数字为最后一个值
    return len(nums)

def missingNumber1(nums):
    # 使用set
    s1, s2 = set(range(len(nums))), set(nums)
    return len(nums) if s1 == s2 else list(s1 - s2)[0]

print(missingNumber([0]))
print(missingNumber1([0]))
print(missingNumber1([3,0,1]))
```