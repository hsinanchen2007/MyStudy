### 解题思路
回溯算法超时，
看了@默蓝 题解。只需考虑每个位置能跳的最远距离就行。
![image.png](https://pic.leetcode-cn.com/807a5cdd09879191c5d4e2d63f93127ea3bad2b4a1f8782cccacd5e9c75767d4-image.png)


### 代码

```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        #回溯算法超时
        # end = len(nums) - 1
        # res = []
        # def backtrack(index,index_num):
        #     if index == end: 
        #         res.append(end)
        #         return
            
        #     for i in range(1,index_num+1):

        #         if (index+i > end) :
        #             return

        #         backtrack(index+i,nums[index+i])

        # backtrack(0,nums[0])
        # return len(res)>0

        max_i = 0
        list_len = len(nums)
        for i,jump in enumerate(nums):
            if max_i>=i and i+jump>max_i:
                max_i = i + jump
            if max_i >= list_len:
                return True
        
        return max_i>=i
```