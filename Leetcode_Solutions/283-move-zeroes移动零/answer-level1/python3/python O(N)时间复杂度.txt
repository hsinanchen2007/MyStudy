遍历一遍列表，找到所有的非0元素下标，按照下标顺序将非0元素放到列表开头，最后将列表剩余部分置0。只有赋值操作，不需要任何交换操作
```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        #找到所有的非0点按照index顺序放到列表开头，然后把列表的剩余部分变0
        index_list_nonZero = []
        for i in range(len(nums)):
            if nums[i] != 0:
                index_list_nonZero.append(i)
        index_len = len(index_list_nonZero)
        #非0元素放到开头
        for i in range(index_len):
            index = index_list_nonZero[i]
            nums[i] = nums[index]
        #列表剩余部分补全0元素
        for j in range(index_len,len(nums)):
            nums[j] = 0
```