### 解题思路1
看了别人的思路写的解法

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res=[-float('inf')]*len(nums)
        maxsum=nums[0]
        res[0]=nums[0]
        if len(nums)<2:
            return maxsum
        for i in range(1,len(nums)):
            if res[i-1]<0:
                res[i]=nums[i]
            else:
                res[i]=res[i-1]+nums[i]
            if res[i]>maxsum:
                maxsum=res[i]
        return maxsum
```

### 解题思路2
自己写的动态规划，但是超时了

### 代码

```python3
def maxSubArray(self, nums: List[int]) -> int:
        res=[-float('inf')]*len(nums)
        res[0]=nums[0]
        temp=0
        maxt=-float('inf')
        for i in range(len(nums)):
            for j in range(i+1):
                temp=sum(nums[j:i+1])
                res[i]=max(res[i],temp)
                if res[i]>maxt:
                    maxt=res[i]
        return maxt
```