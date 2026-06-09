class Solution:
     def maxDistToClosest(self, seats: List[int]) -> int:
        
        one_index = -1  #用于保存上个“1”的位置
        max_dis = 0     #保存最大距离
        
        for index, num in enumerate(seats):
            if num == 1:
                if one_index == -1:     #如果在发现第一个“1”之前都是“0”
                    temp_dis = index
                else:
                    temp_dis = (index - one_index) // 2   #求距离
                if temp_dis > max_dis:
                    max_dis = temp_dis
                one_index = index    #记录新的“1”的位置
        if seats[-1] == 0:   #要考虑最后一个数可能是“0”的情况
            temp_dis = len(seats) - 1 - one_index
            if temp_dis > max_dis:
                max_dis = temp_dis
        
        return max_dis