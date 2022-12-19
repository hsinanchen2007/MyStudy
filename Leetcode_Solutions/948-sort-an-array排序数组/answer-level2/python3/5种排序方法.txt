### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        #冒泡
        for i in range(len(nums)-1):
            for j in range(len(nums)-1, i, -1):
                if nums[j] < nums[j-1]:
                    tmp = nums[j-1]
                    nums[j-1] = nums[j]
                    nums[j] = tmp
        return nums
        #简单选择
        # for i in range(len(nums)-1):
        #     min_index = i
        #     for j in range(i+1, len(nums)):
        #         if nums[j] < nums[min_index]:
        #             min_index = j
        #     if min_index!=i:
        #         tmp = nums[i]
        #         nums[i] = nums[min_index]
        #         nums[min_index] = tmp
        # return nums
        #插入排序
        # for i in range(1, len(nums)):
        #     j = i
        #     target = nums[j]
        #     while j>0 and target<nums[j-1]:
        #         nums[j] = nums[j-1]
        #         j -= 1
        #     nums[j] = target
        # return nums
        #堆排序
        # def heap(nums:List[int],start:int,end:int)->None:
        #     #构造大根堆
        #     i,j = start, 2*start
        #     tmp = nums[start]
        #     while j<=end:
        #         if j<end and nums[j]<nums[j+1]:#比较左儿子和右儿子，j<end确保存在右儿子
        #             j += 1
        #         if tmp < nums[j]:#比较较大儿子和根节点
        #             nums[i] = nums[j]
        #             i = j#递归比较较大儿子节点的堆，由于把较小的根节点替换下来了，因此需要递归比较较大儿子节点和替换下来的根节点
        #             j = 2*i
        #         else:
        #             break#保持大根堆，不需改变
        #     nums[i] = tmp#最终找到根节点的位置
        # def swap(nums:List[int], i:int,j:int)->None:
        #     nums[i], nums[j] = nums[j], nums[i]
        #     return nums
        # def sort(nums:List[int]):
        #     nums = [0]+nums
        #     # print(nums)
        #     Len = len(nums)-1
        #     first_node = Len//2
        #     for i in range(first_node, 0, -1):
        #         heap(nums, i, Len)
        #     # print(nums)
        #     for i in range(Len, 1, -1):
        #         nums = swap(nums, i, 1)
        #         heap(nums, 1, i-1)
        #     return nums[1:]
        # return sort(nums)
        #快排
        def helper(nums, left, right):
            partition = nums[left]
            while left < right:
                while left < right and nums[right]>=partition:
                    right -= 1
                nums[left] = nums[right]
                while left<right and nums[left]<=partition:
                    left += 1
                nums[right] = nums[left]
            nums[left] = partition
            return left
        def sort(nums, left, right):
            if left>=right:
                return 
            mid = helper(nums, left, right)
            sort(nums, left, mid-1)
            sort(nums, mid+1, right)
        sort(nums,0,len(nums)-1)
        return nums
            
        
        
        
```