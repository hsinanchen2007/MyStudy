### 解题思路
1.
排序+双指针

### 代码

```python3
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

'''
作者：JY7k0lf77M
链接：https://leetcode-cn.com/problems/3sum-closest/solution/pai-xu-shuang-zhi-zhen-100-ms-ji-bai-liao-9218-de-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
'''
```