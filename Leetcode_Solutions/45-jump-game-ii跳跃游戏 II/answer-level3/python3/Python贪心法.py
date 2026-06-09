主要思路：在当前最大跳跃步数允许的范围内寻找(当前跳的步数+下次允许跳跃步数)的最大值。


```
def jump(nums):
    """
    跳跃有游戏
    :param 跳跃步数数组
    """
    # 空的
    if len(nums) == 0:
        return 0
    
    loc = 0
    count = 0
    # 跳跃
    while loc < len(nums) - 1:
        # 当前可以跳的最大步数
        max_step = nums[loc]
        # 若果直接可以跳到终点
        if (loc + max_step) >= len(nums) - 1:
            loc += max_step
        # 跳不到(贪心法 当前跳得步数+下次可以跳的最大步数 最大)
        else:
            # 查找下一跳的步数
            step = 0
            total_max_step = 0
            for i in range(0, max_step):
                if (nums[loc + 1 + i] + i + 1) > total_max_step:
                    total_max_step = (nums[loc + 1 + i] + i + 1)
                    step = i + 1
            # 选择最大的
            loc += step
        count += 1
        
    return count
```
