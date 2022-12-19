### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def missingTwo(self, nums: List[int]) -> List[int]:
        n=len(nums)+2
        # 累加和
        pre_sum=sum(range(n+1))
        cur_sum=sum(nums)
        diffSum=pre_sum-cur_sum
        #确认第一个缺失的数
        halMin=diffSum//2
        sumhalf=0
        maxHalfv=(1+halMin)*halMin//2
        for num in nums:
            if num<=halMin:
                sumhalf+=num
        v1=maxHalfv-sumhalf
        v2=diffSum-v1
        return [v1,v2]
```