1. 因为绝对值相同的target值，所需走的步数的一样的，所以只需要考虑target为正的情况
2. 通过累加求和公式 n*(n+1)/2 = abs(target)求方程得到最接近target的步数值a
2. 如果a为整数，则说明a刚好为需要走的最少步数，直接返回a
3. 如果a不为整数，这以min_step = int(a)为起点遍历求和 ` sum = min_step * (min_step + 1) / 2`，遍历结束的条件是(sum - abs_target) 为偶数。至于为什么遍历结束条件为(sum - abs_target)是偶数，这里不再解释，前面的题解有很多讲解。

具体实现如下

```
class Solution(object):
    def reachNumber(self, target):
        """
        :type target: int
        :rtype: int
        """
        abs_target = abs(target)
        a = math.sqrt(2*abs_target + 0.25) - 0.5  # 通过累加求和公式解方程得到
        min_step = int(a)
        if a == min_step:
            return min_step
        sum = min_step * (min_step + 1) / 2
        
        while ( sum < abs_target or (sum - abs_target) % 2 != 0):
            min_step += 1
            sum += min_step
        return min_step 
```

