#### 算法流程：

1. 特判，对于数组长度 $n$ ，如果 $n == 3$ ，返回 $sum(nums)$ 。
2. 对数组进行排序。
3. 遍历排序后数组：
   - 对于重复元素：跳过，优化执行时间；
   - 令左指针 $L = i + 1$，右指针 $R = n - 1$，当 $L < R$ 时，执行循环：
     - 计算 $nums[i] + nums[L] + nums[R]$  三数和，以及与 $target$ 的差 $diff$
     - 如果 $diff$ 的绝对值比 $minDiff$ 小，那么更新 $minDiff$ 和 $closestSum$
     - 如果 $diff == 0$，说明已经找到最接近 $target$ 的和，直接返回
     - 如果 $diff < 0$，说明 $threeSum < target$，$ L$ 右移
     - 如果 $diff > 0$，说明 $threeSum > target$，$R$ 左移

```
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        # 特判：n=3，返回sum(nums)
        n = len(nums)
        if n == 3:
            return sum(nums)
        # 令最小差的绝对值为无限大
        minDiff = float("inf")
        closestSum = 0
        # nums排序
        nums.sort()
        # 遍历nums
        for i in range(n-2):
            if i > 1 and nums[i] == nums[i-1]:
                continue
            # 双指针
            L = i + 1
            R = n - 1
            while(L < R):
                threeSum = nums[i] + nums[L] + nums[R]
                diff = threeSum - target
                # 如果diff的绝对值比minDiff小，那么更新minDiff和closestSum
                if abs(diff) < minDiff:
                    minDiff = abs(diff)
                    closestSum = threeSum
                if diff == 0:
                    # 如果diff为0，直接返回threeSum
                    return closestSum
                elif diff < 0:
                    # 说明threeSum < target，L右移
                    L += 1
                    while(L<R and nums[L]==nums[L-1]):
                        L +=1
                else:
                    # 说明threeSum > target，R左移
                    R -= 1
                    while(L<R and nums[R]==nums[R+1]):
                        R -= 1
        return closestSum
```
