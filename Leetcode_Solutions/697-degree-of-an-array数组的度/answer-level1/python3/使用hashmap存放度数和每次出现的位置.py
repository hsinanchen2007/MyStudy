class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        #用哈希表存放每个元素的信息
        hash_map = {}
        
        #定义最大度数和输出结果
        max_degree = 1
        min_length = 1
        
        #建立哈希表，同时保存最大度数和最小长度
        for index, num in enumerate(nums):
            if num not in hash_map:
                hash_map[num] = [1, index]      #记录每个新素的度和位置
            else:
                hash_map[num][0] += 1
                hash_map[num].append(index)         #每个旧元素度数+1并记录再次出现的位置
                temp_degree = hash_map[num][0]   
                temp_length = hash_map[num][-1] - hash_map[num][1] + 1
                if temp_degree > max_degree:
                    max_degree = temp_degree 
                    min_length = temp_length
                if (temp_degree == max_degree) and (temp_length < min_length):
                    min_length = temp_length
        
        return min_length
            