这个题目开头暗示了n的范围，所以可以加以利用，将元素转换成数组的索引并对应的将该处的元素乘以-1；

若数组索引对应元素的位置本身就是负数，则表示已经对应过一次；在结果列表里增加该索引的正数就行；

class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []
#         把n变成索引：并赋值；
        for n in nums:
            if nums[abs(n)-1] > 0:
                nums[abs(n)-1] *= -1
            else:
                res.append(abs(n))
         
        return res
                