**贪心算法代码，时间内复杂度O(n)，空间复杂度O(1)**
思路：始终找当前位置最大的跳跃数
```
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums)==1:
            return True
        if nums[0]==0:
            return False
        count = 1
        temp = nums[0]
        for i in range(1,len(nums)):
            count+=1
            temp-=1
            if nums[i]>temp:
                temp=nums[i]
            if temp==0:
                break
        if count>=len(nums):
            return True
        return False
```
**动态规划代码，时间复杂度O(n^2)，空间复杂度O(n)**
思路：定义二维数组，所有位置是否被访问，都被访问则返回True
```
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        two_dim_list = [[0 for i in range(n+1)] for i in range(n+1)]
        for i in range(1,n+1):
            temp = nums[i-1]
            if temp+i>=n:
                m = n
            else:
                m = temp+i
            for j in range(i,m):
                two_dim_list[0][j] = 1
        for i in range(1,n):
            if two_dim_list[0][i]!=1:
                return False
        return True
```
