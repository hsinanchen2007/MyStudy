### 解题思路
循环算出k个数的和，
i为0时，算出第一个k个数的和存到临时变量tmp和res中
循环算出第i个k个数的和，存到tmp中；tmp与res比，把最大值放res中
循环完成后，就找出最大的和了
最后返回时算出平均数

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