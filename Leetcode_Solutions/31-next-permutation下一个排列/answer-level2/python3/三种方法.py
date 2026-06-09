```
    def nextPermutation1(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        size = len(nums)
        if size <= 1: return
        for i in range(size - 2, -1, -1):
            if nums[i] < nums[size - 1]:  # 可调换
                # 查找在 i 右侧中次大于 nums[i] 的值
                j = size - 1
                while j > i and nums[i] < nums[j]:
                    j -= 1
                nums[i], nums[j + 1] = nums[j + 1], nums[i]
                break
            else:
                # 不可调换时, 将 i 右侧的均左移一个, 并将原 i 位置处移至末尾
                cur = nums[i]
                j = i
                while j < size - 1:
                    nums[j] = nums[j + 1]
                    j += 1
                nums[size - 1] = cur

    def nextPermutation2(self, nums: List[int]) -> None:
        length = len(nums)
        if length <= 1: return
        possible = False
        for i in range(2, length + 1):
            for j in range(1, i):
                if nums[-i] < nums[-j]:
                    possible = True
                    nums[-i], nums[-j] = nums[-j], nums[-i]
                    break
            if possible:
                break
        sort_length = i - 1 if possible else length
        left, right = -sort_length, -1
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1
        return

    def nextPermutation(self, nums: List[int]) -> None:
        size = len(nums)
        if size <= 1: return
        i = size - 2
        start = 0
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        if i >= 0:  # 存在下一个更大的排列
            # 查找 i 右侧次大于 nums[i] 的值
            start = i + 1
            j = start
            while j < size and nums[j] > nums[i]:
                j += 1
            nums[i], nums[j - 1] = nums[j - 1], nums[i]
        # 二分交换
        for k in range((size - start) // 2):
            nums[start + k], nums[size - k - 1] = nums[size - k - 1], nums[start + k]
```