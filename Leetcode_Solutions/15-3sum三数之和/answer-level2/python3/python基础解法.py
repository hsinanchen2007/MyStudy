### 解题思路
主要思路就是排序加双指针，类似于twosum问题，a+b+c = 0等于a+b=-c。

### 代码

```python3
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = list()
        nums.sort()
        n = len(nums)
        if(not nums or n<3):
            return []
        for i in range(n-2):
            # 减少重复计算，因为相同的只放一个
            if i > 0 and nums[i] == nums[i-1]:
                continue
            # 大于0后面就不用算了
            if nums[i] > 0:
                break
            x = i+1
            y = n-1
            while x<y:
                if nums[i] + nums[x] + nums[y] == 0:
                    result.append([nums[i], nums[x], nums[y]])
                    # 减少重复计算
                    while x<y and nums[x] == nums[x+1]:
                        x += 1
                    while x<y and nums[y] == nums[y-1]:
                        y -= 1
                    x += 1
                    y -= 1
                elif nums[i] + nums[x] + nums[y] > 0:
                    y -= 1
                else:
                    x += 1
        return result
```