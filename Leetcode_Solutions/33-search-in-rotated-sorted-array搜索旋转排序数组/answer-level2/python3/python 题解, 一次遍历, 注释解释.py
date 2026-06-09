注意点都在注释中, 好久没法 leetcode 题解了, 如果有兴趣的话, 可以关注我的 B 站账号, 佛系刷题, 大家多多交流啊

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        while left <= right:
            middle = (left + right) // 2
            if nums[middle] >= nums[left]:
                # 这里的 >= 十分重要, 因为 middle 一直十分靠近 left,
                # 这里的等于能确保只有两个元素是, 保持左侧及时只有一个元素, 也将其看作是升序的,
                # 因为你无法判断右侧是不是升序的, 但是一个元素必然是升序的
                # 说明左侧是升序的
                if nums[left] <= target < nums[middle]:
                    right = middle - 1
                elif target == nums[middle]:
                    return middle
                else:
                    left = middle + 1
            else:
                # 说明右侧是升序的
                if nums[middle] < target <= nums[right]:
                    left = middle + 1
                elif nums[middle] == target:
                    return middle
                else:
                    right = middle - 1
        return -1
```