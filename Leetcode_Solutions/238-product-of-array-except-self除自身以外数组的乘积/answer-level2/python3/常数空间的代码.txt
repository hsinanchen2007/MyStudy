### 解题思路
优化空间，就是在节约原本由于存储左右乘积的额外数组。简单来说就是利用最后的返回数组提前将左右乘积存入，这需要在双向同时遍历，同时维护左积和右积，并并行更新返回数组。举个例子，在[1,2,3,4]中，返回数组res变化顺序为[1,1,1,1]，[1,1,4,1]，[1,12,8,1]，最后是[24,12,8,6]

### 代码

```python3
class Solution:
    #乘积等于左积和右积
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        lth=len(nums)
        res=[1 for _ in range(lth)]
        for pos in range(lth):
            if pos==0:
                left=nums[pos]
                right=nums[lth-1-pos]
            else:
                res[pos]*=left
                res[lth-1-pos]*=right
                left*=nums[pos]
                right*=nums[lth-1-pos]
        return res
```