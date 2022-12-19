class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        
        record = [[1] * 2 for i in range(len(nums))]
        # print (record)
        for i1 in range(1, len(nums)):
            for i2 in range(i1):
                if nums[i2] < nums[i1]:
                    record[i1][0] = max(record[i1][0], record[i2][1] + 1)
                if nums[i1] < nums[i2]:
                    record[i1][1] = max(record[i1][1], record[i2][0] + 1)
        
        # print (record)
        
        return max(record[-1])



利用动态规划从第一个到最后一个数组，每一个状态定义为此前为之前为正序的最大长度和之前为逆序的最大长度、分别存储在list中的第一个元素的位置和第二个元素的位置。
经过迭代到最后一个元素的时候就可以统计出最多的摆动结果