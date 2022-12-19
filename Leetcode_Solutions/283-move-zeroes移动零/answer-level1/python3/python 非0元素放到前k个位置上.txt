### 解题思路

第一步：把非零元素移到前k个位置上   
[0,1,0,3,12] -> [1,3,12,...]就是[1,3,12,3,12]

第二步：把剩余元素置零   
 [0,1,0,3,12] -> [1,3,12,3,12] ->  [1,3,12,0,0]
```

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        k=0
        for num in nums:
            if num !=0:
                nums[k] = num
                k+=1

        for i in range(k,len(nums)):
            nums[i]=0


