### 解题思路
贪心算法

### 代码

```python3
class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums)<2:
            return 0
        cnt=0
        finalPos=len(nums)-1
        pos=0
        while(1):
            step=nums[pos]
            if pos+step>=finalPos:
                return cnt+1
            maxDist=0
            jumpStep=0
            for s in range(1,step+1):
                if s+nums[pos+s]>=maxDist:
                    maxDist=s+nums[pos+s]
                    jumpStep=s
            pos=pos+jumpStep
            cnt+=1
```