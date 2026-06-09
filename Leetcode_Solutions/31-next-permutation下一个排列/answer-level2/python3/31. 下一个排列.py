解释在代码里，给出了为什么采用这种方法能达到排序的目的和找到下一个字典更大串，如果不清楚可以一起讨论。自己举一个例子并按字典顺序写出所有排列观察规律应该有助于理解
```
class Solution:
    def nextPermutation(self, nums: list) -> None:
        firstIndex = -1
        n = len(nums)
        for i in range(n - 2, -1, -1):
            """查找第一队满足nums[i] < nums[i+1]的元素，若存在则表明下标i+1后面的元素都满足nums[i] > nums[i+1],即使降序序列"""
            if nums[i] < nums[i + 1]:
                firstIndex = i
                break

        # 若没有满足nums[i] < nums[i+1]的情况则整个序列是降序序列,则 firstIndex == -1
        if firstIndex > -1:
            secondIndex = -1
            # 从序列最后一个元素开始找比firstIndex下标指向元素大的元素，也即是将下标firstIndex指向的元素按插入法排序插入到firstIndex后的降序序列中去
            for i in range(n - 1, firstIndex, -1):
                if nums[i] > nums[firstIndex]:
                    secondIndex = i
                    break
            nums[firstIndex], nums[secondIndex] = nums[secondIndex], nums[firstIndex]
        # 反转以firstIndex+1下标元素为起始元素的降序序列
        self.reverse(nums, firstIndex + 1, n - 1)

    def reverse(self, nums, i, j):
        """列表反转"""
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1
```