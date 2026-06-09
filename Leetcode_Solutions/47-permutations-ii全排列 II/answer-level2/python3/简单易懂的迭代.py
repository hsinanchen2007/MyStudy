![image.png](https://pic.leetcode-cn.com/639d517a67f7270e9b7c3ccf5f2fe0947aae6b8ce03ba7810bed0d5d826741b4-image.png)

### 解题思路
对应数学Cnn
和全排列I相同，只是这里有重复元素，只需要添加一个判断即可，记当前迭代如果后面还有相同元素，或者之前有相同元素就跳过

### 代码

```python3
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        def itermute(nums,mm):
            if not nums:
                res.append(mm)
                return
            for i in range(len(nums)):
                if nums[i] in nums[i+1:]:
                    continue
                itermute(nums[:i]+nums[i+1:],mm+[nums[i]])
        itermute(nums,[])
        return res
```