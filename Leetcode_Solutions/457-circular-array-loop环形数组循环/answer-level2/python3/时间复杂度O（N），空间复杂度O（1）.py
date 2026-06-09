### 解题思路
用mark标记每轮检验的循环，其中mark的初始值为0.1，每个值用完之后就标位mark，当循环之后，遇到某位置的值为mark，则代表循环成功，返回True。每轮检验后mark除以10。当遇到别的mark值，则循环失败。
在每一轮检验起始，sig等于第一个值作为标记，以此检验，循环中的值是否都为正数或负数，若不同，则跳出循环。

### 代码

```python3
class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        mark=0.1
        for i in range(len(nums)):
            if 0<nums[i]<1:continue
            sig=nums[i]
            next_pos=i
            while True:
                if nums[next_pos]==mark:return True
                elif 0<nums[next_pos]<1:break
                elif abs(nums[next_pos])%len(nums)==0:
                    nums[next_pos]=mark
                    break
                elif nums[next_pos]*sig<0:break
                else:
                    m=next_pos+nums[next_pos]
                    if m>=len(nums):m=m%len(nums)
                    while m<0:
                        m+=len(nums)
                    nums[next_pos]=mark
                    next_pos=m
            mark/=10
        return False
```