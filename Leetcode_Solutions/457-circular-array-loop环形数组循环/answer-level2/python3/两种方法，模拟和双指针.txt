### 解题思路
此处撰写解题思路

### 代码

```python3
# class Solution:
#     def circularArrayLoop(self, nums: List[int]) -> bool:
#         visited = set()
#         N = len(nums)

#         for i in range(N):
#             if i in visited:
#                 continue  
#             move = nums[i]
#             visited.add(i)
#             numSet = set()
#             numSet.add(i)
#             j = (i+nums[i]) % N
#             while j not in visited:
#                 visited.add(j)
#                 if nums[j]*move<0:
#                     move = nums[j]
#                     numSet = set()
#                     numSet.add(j)
#                     j = (N + j + nums[j]) % N
#                 else:
#                     numSet.add(j)
#                     j = (N + j + nums[j]) % N

#                 if (N + j + nums[j]) % N == j:
#                     numSet = set()
#                 elif j in numSet and len(numSet) >= 2:
#                     return True
#         return False
# class Solution:
#     def circularArrayLoop(self, nums: List[int]) -> bool:

#         def nextPos(nums, curr):
#             totLen = len(nums)
#             nextP = curr + nums[curr]
#             while nextP < 0:
#                 nextP += totLen
#             return nextP % totLen

#         for i in range(len(nums)):
#             if nums[i] != 0:
#                 slow, fast = i, i
#                 l = 0
#                 while True:
#                     nextSlow = nextPos(nums, slow)
#                     if nextSlow == slow or nums[nextSlow] == 0 or nums[i]*nums[nextSlow] < 0:
#                         nums[i] = 0
#                         break
#                     slow = nextSlow
#                     nextFast = nextPos(nums, fast)
#                     if nextFast == fast or nums[nextFast] == 0 or nums[i]*nums[nextFast] < 0:
#                         nums[i] = 0
#                         break
#                     fast = nextFast
#                     nextFast = nextPos(nums, fast)
#                     if nextFast == fast or nums[nextFast] == 0 or nums[i]*nums[nextFast] < 0:
#                         nums[i] = 0
#                         break
#                     fast = nextFast
#                     if slow == fast:
#                         return True
#         return False
class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        def _Next(i):
            return (nums[i]+i)%N

        N = len(nums)
        for i in range(N):
            if nums[i]==0: continue 
            s = i # 慢指针代表当前位置
            f = _Next(i) # 快指针代表下一个位置
            # 快慢指针同向且慢指针和快指针下一个也要同向
            while(nums[s]*nums[f]>0 and nums[s]*nums[_Next(f)]>0):
                # if s==f: # 快慢指针相遇
                #     if s==_Next(s):
                #         break # 循环长度为1的情况
                #     return True
                if s==f and s!=_Next(s):return True
                elif s==_Next(s): break
                s = _Next(s)
                f = _Next(_Next(f))
        return False
```