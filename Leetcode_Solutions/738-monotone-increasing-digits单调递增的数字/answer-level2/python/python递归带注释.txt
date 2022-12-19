
```
class Solution(object):
    def monotoneIncreasingDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        # 把数字转换成list
        nums = map(int, str(N))
        # idx：初始末尾索引
        idx = len(nums)-1  
        while idx >= 0:
            # 每次返回上一层递归更新的索引位置，若idx不为0，则进入下一次递归
            idx = self.subIncreasingDIgits(nums, 0, idx+1) 
            # 若返回的idx为0，说明数组中没有发生元素更新，当前数组已经是递增的，返回
            if idx == 0:
                return self.list2val(nums)
            
            
    def subIncreasingDIgits(self, nums, start, end):
        '''
        将nums数组中，子数组nums[start, end]的部分转换成递增的
        '''
        flag = True
        for i in range(start, end-1):
            if nums[i+1] >= nums[i]:         
                continue
            # 把nums[i-1]减1，将nums[i]开始的数都变成9
            nums[i] -= 1
            # 记录更新的位置索引为idx
            idx = i
            # 将nums[i]开始的数都变成9
            for j in range(i+1, end):
                nums[j] = 9
            flag = False
        # 返回更新的位置索引
        return idx if not flag else 0
    
    def list2val(self, nums):
        '''
        将数组转换成数字
        '''
        n = len(nums)
        ans = 0
        for i in range(n):
            ans += nums[i]*(10**(n-i-1))
        return ans
            
```
