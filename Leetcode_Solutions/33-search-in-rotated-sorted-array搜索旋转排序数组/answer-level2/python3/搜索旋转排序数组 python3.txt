### 解题思路
比较目标值和数组的头元素和尾元素
如果target等于头元素：返回0
如果target等于尾元素：返回len(nums)-1
如果target大于头元素：正序遍历数组并与target进行比较，结束标志为数组元素出现减小
如果target小于尾元素：逆序遍历数组并与target进行比较，结束标志为数组元素出现变大
其他情况之间返回-1


### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return -1
        if len(nums) == 1:
            if nums[0] == target: return 0
            else: return -1
        head = 0
        tail = len(nums)-1
        if target == nums[head]:
            return head
        elif target == nums[tail]:
            return tail
        elif target > nums[head]:
            for i in range(len(nums)-1):
                if nums[i] == target:
                    return i
                if nums[i+1] < nums[i]:
                    return -1
            return -1
        elif target < nums[tail]:
            for i in range(len(nums)-1, -1, -1):
                print(nums[i])
                if nums[i] == target:
                    return i
                if nums[i-1] > nums[i]:
                    return -1
            return -1
        else:
            return -1     
```