### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []
        temp0 = float('-inf') #负穷大
        temp = temp0
        for i in range(len(nums)):     
            temp = max(temp, nums[i])   #窗口的最后一个值与前缀最大值比较
            if i > k-2:                 #判断到达窗口长度
                res.append(temp)
                if temp <= nums[i-k+1]: #如果即将滑出窗口的值可能是最大值，重新计算下个窗口前缀temp的值
                    temp = temp0
                    for j in range(k-1):
                        temp = max(temp, nums[i-j])
                    
        return res
```