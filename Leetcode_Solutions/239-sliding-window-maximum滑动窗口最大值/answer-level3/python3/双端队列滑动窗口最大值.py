本题可以考虑：
（1）使用暴力解法：依次遍历数组元素，再在当前窗口中找出最大值：O（n*k）复杂度;
（2）使用双端队列，队列中元素单调递减，当从队尾新加入元素时弹出队首元素以及队列中小于当前元素的值，队首元素的值即为窗口最大值：线性时间复杂度；

    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        #暴力解法，复杂度O(n*k)：
        
        res = []
        if not nums:
            return res
        #定义滑动窗口，每次从窗口中找出最大值放入结果数组中
        for index in range(len(nums)-k+1):
            res.append(max(nums[index:index+k]))
        return res

--------------------------------------------------------------------------------------

    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        
        #利用双端队列实现线性时间:
        from collections import deque
        q = deque()
        res = []
        
        #遍历数组，维护双端队列：
        for index,num in enumerate(nums):
            #队首弹出规则：
            if len(q) > 0 and q[0][0] == index-k:
                q.popleft()
            #队尾入队规则（[index, num]表示[时间戳，数值]）：
            while len(q) > 0 and q[-1][1] <= num:
                q.pop()
            q.append([index, num])
            #获取队首元素,即当前窗口最大值：
            if index >= k-1:
                res.append(q[0][1])
        
        return res