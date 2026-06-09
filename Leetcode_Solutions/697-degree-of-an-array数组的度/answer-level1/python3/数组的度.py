### 解题思路
#### 原作者：LeetCode官方

### 代码

```python3
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        # 最后一个出现元素index - 第一个出现元素index + 1
        left, right, count = {}, {}, {}
        for i, x in enumerate(nums):
            if x not in left: 
                left[x] = i
            right[x] = i
            count[x] = count.get(x, 0) + 1

        ans = len(nums)
        degree = max(count.values())
        for x in count:
            if count[x] == degree:
                ans = min(ans, right[x] - left[x] + 1)

        return ans

        # if len(nums) <= 1:
        #     return len(nums)

        # distance = []
        # for left in range(len(nums)-1):
        #     count = []
        #     for right in range(left+1, len(nums)):
        #         if nums[left] == nums[right]:
        #             count.append(left)
        #     count.append(right)
        #     distance.append(count)
        # minDis = []
        # for item in distance:
        #     minDis.append(max(item) - min(item) + 1)
        # print(minDis)
        # return min(minDis)

        


```