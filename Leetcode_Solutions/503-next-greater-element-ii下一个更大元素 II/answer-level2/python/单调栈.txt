### 解题思路
学习自labuladong

### 代码

```python3
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        #学习自labuladong
        #不循环 Done:
        # s = []#stack
        # ans = [0 for _ in range(len(nums))]
        # for i in range(len(nums) - 1, -1, -1):
        #     #print(i)
        #     while(s and s[-1] <= nums[i]):
        #         s.pop()
        #     ans[i] = -1 if not s else s[-1]
        #     s.append(nums[i])
        # return ans
        #循环1: 直接doublenums:更容易理解
        # nums = nums * 2
        # #print(nums)
        # s = []#stack
        # ans = [0 for _ in range(len(nums))]
        # for i in range(len(nums) - 1, -1, -1):
        #     #print(i)
        #     while(s and s[-1] <= nums[i]):
        #         s.pop()
        #     ans[i] = -1 if not s else s[-1]
        #     s.append(nums[i])
        # #print(ans)
        # return ans[:len(nums)//2]
        #循环2: 在循环1的基础上 环形数组, 空间节省, 依然循环两次
        n = len(nums)
        s = []#stack
        ans = [0 for _ in range(len(nums))]
        for i in range(2*n -1, -1, -1):
            while(s and s[-1] <= nums[i % n]):
                s.pop()
            ans[i % n] = -1 if not s else s[-1]
            s.append(nums[i%n])
        return ans
```