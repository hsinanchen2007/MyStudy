### 解题思路
借鉴3sum的思路，先将数组排序，固定一个值，使用双指针搜索，每次比较3sum和target的gap，如果gap变小了，保存最新的3sum。排序好的双指针能减少时间复杂度，当3sum的值比target小，需要增大3sum，左指针向右，反之右指针向左

### 代码

```python
class Solution(object):
    def threeSumClosest(self, nums, target):
        nums.sort()
        l = len(nums)
        result = nums[0]+nums[1]+nums[2]
        gap = max(target, result) - min(target, result)
        for i in range(l):
            j = i+1
            k = l-1
            while j < k:
                t= nums[i]+nums[j]+nums[k]
                tmp = max(t, target) - min(t, target)
                if tmp < gap:
                    gap = tmp
                    result = t
                if gap == 0:
                    return result
                if t > target:
                    k-=1
                else:
                    j+=1
        return result
```