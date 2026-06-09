### 思路一
直接从前遍历，遇到一个数就把所有子集加上该数组成新的子集，遍历完毕即是所有子集.
注意代码中注释的地方，必须是res[:]，而不是res,因为此时循环中res[:]是不更新的，而res是不断有元素push进去的.
### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res=[[]]
        for i in range(len(nums)):
            for sub in res[:]:         ##必须res[:]
                res.append(sub+[nums[i]])
        return res
```

### 思路二：迭代（思想与思路一一致）

### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res=[[]]
        for i in nums:
            res=res+[[i]+num for num in res]
        return res
```

### 思路三：回溯（递归）

### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        
        def helper(i, tmp):
            res.append(tmp)
            for j in range(i, n):
                helper(j + 1,tmp + [nums[j]] )
        helper(0, [])
        return res  
```