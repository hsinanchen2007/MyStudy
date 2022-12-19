### 解题思路
看看修改了一个元素后的数组是不是递增的就完事了

### 代码

```python3
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        nums.append(10e5)
        for i in range(len(nums)-1):
            if nums[i]>nums[i+1]:
                if nums[i]>nums[i+2]: #nums[i]过大了，改小
                    nums[i]=nums[i+1]
                else:                 #nums[i+1]过小了，改大
                    nums[i+1]=nums[i]
                return nums==sorted(nums) #检验修改后是否递增
        return True  #如果没有逆序发生
                
```