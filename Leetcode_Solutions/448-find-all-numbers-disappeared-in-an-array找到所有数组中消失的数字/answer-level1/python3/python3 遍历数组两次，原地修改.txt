### 解题思路
与官方题解2类似。第一次遍历加负号做为标记；第二次找到未变为负数的数组位置。
时间复杂度：O(n)
空间复杂度：O(1)

### 代码

```python3
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        res=[]
        for num in nums:
            if nums[abs(num)-1]>0:
                nums[abs(num)-1]*=-1
        for i in range(len(nums)):
            if nums[i]>0:
                res.append(i+1)
        return res
```