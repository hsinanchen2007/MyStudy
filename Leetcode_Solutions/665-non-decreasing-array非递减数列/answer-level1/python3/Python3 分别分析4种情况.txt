### 解题思路
先nums = [float('-inf')] + nums + [float('inf')] 防止溢出

![屏幕快照 2020-04-05 下午9.19.03.png](https://pic.leetcode-cn.com/ea62d20c2dd3fd3deeb71e2112dc85c2fd7cb335af99e3eb87bb64896e6b363e-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-04-05%20%E4%B8%8B%E5%8D%889.19.03.png)

### 代码

```python3
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        nums = [float('-inf')] + nums + [float('inf')]
        count = 0
        if not nums: return False
        if len(nums) < 2: return True

        for i in range(1, len(nums) - 1):
        #     if(nums[i] <= nums[i + 1]):
        #         pass
        #     else:
        #         count += 1
        #         tmp = nums[i]
        #         nums[i] = nums[i - 1] #p+1 >p-1的解决方案
        #         #p+1 < p -1:
        #         if(nums[i] > nums[i + 1]):
        #             nums[i] = tmp
        #             nums[i+1] = tmp
        #     if(count == 2):
        #         return False
        # return True
            if nums[i] <= nums[i+1]:
                continue
            else:
                count += 1
                #tmp = nums[i]
                #p+1 >p-1的解决方案
                if nums[i+2]>= nums[i]:
                    nums[i+1] = nums[i]
                elif nums[i+2] < nums[i] and nums[i+1]>=nums[i-1]:
                    nums[i] = nums[i+1]
                else:
                    return False
            if count == 2: return False
        return True

```