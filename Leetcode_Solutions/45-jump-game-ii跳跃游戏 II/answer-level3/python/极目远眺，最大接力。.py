### 解题思路
站在当前位置，向前极目远眺，从视野之内选择：max(位置+其视距),的那个位置作为吓一跳。 就可尽快到达终点。

### 代码

```python3
class Solution:
    def jump(self, nums):
        if len(nums)==1:return 0
        start,ans=0,0
        while True:
            #print('current pos: %d'%start)
            if nums[start]+start>=len(nums)-1:
                return ans+1
            # 下一跳选择：当前射程中的某个位置 再出发的 最大射程
            nextJumpValue,nextJumpPos=0,0
            for i in range(start+1,nums[start]+start+1):
                if nums[i]+i>=nextJumpValue:
                    nextJumpValue=nums[i]+i
                    nextJumpPos=i

            start=nextJumpPos
            ans+=1
        return ans
```