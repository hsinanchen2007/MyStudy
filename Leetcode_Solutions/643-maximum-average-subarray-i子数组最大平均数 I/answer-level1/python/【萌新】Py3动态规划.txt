### 解题思路
每次取出nums[i:i+k]的窗口，计算sum，返回sum最大的窗口即可

### 代码

```python3
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        length=len(nums)
        res=tmp=0

        for i in range(length-k+1):
            if i == 0:
                tmp=res = sum(nums[i:i+k])
            else:
                tmp += nums[i+k-1]-nums[i-1]
                res = max(tmp, res)
        
        return res/k


```