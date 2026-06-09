题目分析：因为这是一个非负整数的列表， 所以能不能到达数组最后位置的关键在于‘可不可以跨过数组中的0’，
算法设计：1.确定for范围, 无需考虑最后一个数
         2.遍历nums的过程中，找到0， 比对之前的0之前的数是否可以跨过0
        
        for i in range(len(nums)-1):
            if nums[i] == 0:
                pass_ = False
                index = i - 1
                while not pass_ and index >= 0:
                    if nums[index] > i - index:
                        pass_ = True
                    else:
                        index -= 1
                        
                if pass_ is False:
                    return False
        
        else:
            return True
