```python
def maxProduct(nums):
    """
        1. dp问题: 定义两个数组max_stack存储当前乘积最大值, min_stack存储当前乘积最小值.
        2. 因为存在负数, 所以才需要max_stack, min_stack.
        3. dp[i] = dp[i - 1] * nums[i]
        4. dp[i - 1]需要根据max_stack, min_stack计算出来.
    """
    if not nums:
        return 0
    max_stack, min_stack = [nums[0]], [nums[0]]
    for i in range(1, len(nums)):
        n1, n2, n3 = max_stack[-1] * nums[i], min_stack[-1] * nums[i], nums[i]
        max_stack.append(max(n1, n2, n3))
        min_stack.append(min(n1, n2, n3))
    
    return max(max_stack)

print(maxProduct([2,3,-2,4]))
print(maxProduct([-2,0,-1]))
```