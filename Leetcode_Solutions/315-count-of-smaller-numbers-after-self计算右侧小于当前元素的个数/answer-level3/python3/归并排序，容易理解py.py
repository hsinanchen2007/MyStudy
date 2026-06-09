归并排序，我觉得写得很好理解吧。。。
```
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        # 使用索引数组
        n = len(nums)
        index = [i for i in range(n)]
        res = [0 for i in range(n)]
        # 归并
        self.__merge(nums, index, res)
        return res
    def __merge(self, nums, index, res):
        if len(index) <= 1:
            return
        mid = len(index) // 2
        left = index[:mid]
        right = index[mid:]
        self.__merge(nums, left, res)
        self.__merge(nums, right, res)
        i = 0
        j = 0
        k = 0
        # 归并逻辑处理
        while i < mid:
            while j < len(right) and nums[left[i]] > nums[right[j]]:
                j += 1
            res[left[i]] += j
            i += 1
        # 归并排序过程
        i = 0
        j = 0
        k = 0
        while i < len(left) and j < len(right):
            if nums[left[i]] < nums[right[j]]:
                index[k] = left[i]
                k += 1
                i += 1
            else:
                index[k] = right[j]
                k += 1
                j += 1
            # 总有一个越界
        while i < len(left):
            index[k] = left[i]
            k += 1
            i += 1
        while j < len(right):
            index[k] = right[j]
            k += 1
            j += 1
```
