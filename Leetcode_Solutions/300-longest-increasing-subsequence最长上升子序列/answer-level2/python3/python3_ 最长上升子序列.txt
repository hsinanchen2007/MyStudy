```python
def lengthOfLIS(nums):
    """
        1. dp问题, dp[i] = max(dp[j]) + 1, 其中nums[j] < nums[i], 并且0<=j<i
        2. dp[i]存储出现的次数, 以及对应的值
    """
    if not nums:
        return 0
    # 之所以用元祖, 因为元祖可排序
    stack = [(1, nums[0])]
    for i in range(1, len(nums)):
        # 找到所有满足上升的元素
        _s = [s for s in stack if s[1] < nums[i]]
        if not _s:
            # 如果没有, 则次数为1
            stack.append((1, nums[i]))
        else:
            # 按照出现的次数排序
            _s.sort(key=lambda a: a[0])
            # 最大的次数 + 1(代表当前的值)
            stack.append((_s[-1][0] + 1, nums[i]))
    
    return max(stack)[0]
            
print(lengthOfLIS([10,9,2,5,3,7,101,18]))
```