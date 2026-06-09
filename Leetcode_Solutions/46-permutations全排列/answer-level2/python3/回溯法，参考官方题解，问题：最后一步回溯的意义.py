### 解题思路
回溯法，仍然不懂最后一步回溯的意义。

### 代码

```python3
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def backtrack(first=0):
            if first==n:
                ##这是因为数组的名nums指向的是数组的内存地址，而对于回溯法来说，操作完成之后的回溯都使数组还原到原来                  ##的样子，因此你append的所有东西都指向同一个地址。而nums[:]返回的是nums的拷贝
                ans.append(nums[:])
            for i in range(first, n):
                nums[first], nums[i] = nums[i], nums[first]
                backtrack(first+1)
                ##回溯
                nums[first], nums[i] = nums[i], nums[first]
            return ans
        ans = []
        n = len(nums)
        backtrack()
        return ans
        
```