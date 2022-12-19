```
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        head = 0
        tail = len(nums)
        if nums[0] >= target:
            return head
        # 注意当最后一位小于目标值是返回值跟等于目标值时不同
        elif nums[tail - 1] < target:
            return tail
        elif nums[tail - 1] == target:
            return tail-1
        else:
            # 二分法，注意终止条件不是头尾相等
            while (tail - head != 1):
                # 注意python3中//代表地板除，%是取余，/是数学意义上的除法
                if nums[(tail - head) // 2 + head] == target:
                    return (tail - head) // 2 + head
                elif nums[(tail - head) // 2 + head] > target:
                    tail = (tail - head) // 2 + head
                else:
                    head = (tail - head) // 2 + head
            return tail
```
