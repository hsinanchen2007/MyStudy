### 解题思路
初始化定义`target`首尾位置`start, end = -1, -1`

遍历`nums`，会出现三种情况：
1. `nums[i]`大于`target`，无需继续遍历
2. `nums[i]`小于`target`，继续看下一个元素
3. `nums[i]`等于`target`，分为两种情况：
    - 如果`start`等于-1，说明这是第一次遇到`target`，同时更新`start`和`end`，以备这是最后一个`target`
    - 如果`start`不等于-1，只更新`end`即可
### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        start, end = -1, -1
        for i in range(len(nums)):
            if nums[i] > target:
                break
            elif nums[i] < target:
                continue
            elif nums[i] == target:
                if start == -1:
                    start, end = i, i
                else:
                    end = i
        return [start, end]
```