### 解题思路
在True的区域生长步长标为True

### 代码

```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums)<=1:
            return True
        ans = [False for i in range(len(nums))]
        ans[0] = True
        for i in range(0,len(nums)):
            if ans[i]==True:
                ans[(i+1):(i+(nums[i])+1)] = [True]*nums[i]
            else:
                break
        #print(ans)
        return ans[len(nums)-1]


        '''
        if len(nums)<=1:
            return True
        ans = [False for i in range(len(nums))]
        ans[0] = True
        #print(ans)
        for i in range(1,len(nums)):
            start = 0
            #end = i
            an = False
            #print(type(ans))
            #print(ans[start])
            while start<=i:
                an = (an or (ans[start] and (nums[start]>=(i-start))))
                start += 1
            ans[i] = an
            #print(an)
            #print(i)
        #print(ans)
        return ans[-1]
        '''       
```