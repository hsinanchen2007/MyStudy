**暴力解法（超出时间限制）：**
    **很容易想到，可以先确定ai和ak，循环遍历数组查找符合要求的aj，需要三重循环，时间复杂度是O(n3)。更好的方法是，用栈存放已经找到的[最小值，最大值],遍历整个数组，根据当前数替换栈顶的范围，当当前数位于栈顶表示的范围时，返回True，复杂度是O(n)**

    
    def find132pattern(self, nums: List[int]) -> bool:
        #暴力解法：
        for i in range(len(nums)-2):
            for j in range(i+1, len(nums)-1):
                if nums[j] <= nums[i]:
                    continue
                else:
                    for k in range(j+1, len(nums)):
                        if nums[k] >= nums[j] or nums[k] <= nums[i]:
                            continue
                        else:
                            return True
        return False

    

    def find132pattern(self, nums: List[int]) -> bool:
        
        stock = []   #存放最小值和最大值的栈：[最小值，最大值]
        
        #循环遍历数组中的数：
        for num in nums:
            #如果栈为空，或当前数小于栈顶位置的最小值
            if len(stock) == 0 or num < stock[-1][0]:  
                stock.append([num, num])
            else:
                top_min = stock[-1][0]    #保存最小值
                while (len(stock) != 0) and (num > stock[-1][1]):   #如果当前数大于栈顶最大值，意味着可以用新的范围作为栈顶
                    stock.pop()
                if (len(stock) != 0) and (num > stock[-1][0]) and (num < stock[-1][1]):
                    return True
                stock.append([top_min, num])
        return False