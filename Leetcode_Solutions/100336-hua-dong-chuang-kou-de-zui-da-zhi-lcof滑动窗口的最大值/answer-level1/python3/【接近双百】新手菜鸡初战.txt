```
class Solution:
    def maxSlidingWindow(self, nums, k):
        if not nums:
            return []
        result = []  # 结果
        max_index = 0  # 最大值的索引位置
        left_index = 0  # 左边索引
        right_index = k - 1  # 右边索引
        len_ = len(nums) - 1  # 长度
        # 初始化第一次遍历，查出最大值
        for i in range(left_index, right_index + 1):
            if nums[i] >= nums[max_index]:
                max_index = i
        result.append(nums[max_index])

        # 遍历到最右边
        while right_index < len_:
            # 如果最大值不是最左边的位置
            if max_index > left_index:
                left_index += 1
                right_index += 1

                # 如果新进来的值大于等于最大值
                if nums[right_index] >= nums[max_index]:
                    max_index = right_index

            # 重新查询新窗口的最大值
            else:
                left_index += 1
                right_index += 1
                max_index = left_index
                for i in range(left_index, right_index + 1):
                    if nums[i] >= nums[max_index]:
                        max_index = i

            # 添加本次窗口最大值
            result.append(nums[max_index])

        return result
```

