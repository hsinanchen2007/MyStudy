### 解题思路
方向不同直接跳出！

### 代码

```python3
class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        size=len(nums)
        if size<=1:
            return False
        for i in range(size):
            Set=set()
            idx=i
            length=0
            while idx not in Set:
                flag1=True if nums[idx]>0 else False
                Set.add(idx)
                length+=1
                idx=idx+nums[idx]
                if idx>=0:
                    idx%=size
                else:
                    while idx<0:
                        idx+=size
                flag2=True if nums[idx]>0 else False
                if flag1^flag2:
                    break
            if i==idx and length>1:
                return True
            
        return False
```