### 解题思路
此处撰写解题思路

### 代码
[偷来的](https://leetcode-cn.com/problems/subsets-ii/solution/zai-zi-ji-de-ji-chu-shang-zeng-jia-qu-zhong-python/)

```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def recursion(num: int, cur_len :int):
            if cur_len == 1:
                res.append([])
                res.append([num])
            else:
                sub = res[:]
                for item in sub:
                    res.append(item+[num])
                
        res = []
        for index, num in enumerate(nums):
            recursion(num, index+1)
        return res

```

我的：
```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []
        ans,n = [[]],len(nums)
        for i in range(n):
            for x in range(2**i):
                ans.append(ans[x]+[nums[i]])
        return ans

```
### [二进制模拟](https://leetcode-cn.com/problems/subsets/solution/er-jin-zhi-wei-zhu-ge-mei-ju-dfssan-chong-si-lu-9c/)
```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []
        ans,n = [],len(nums)
        for i in range(1<<n):
            temp = []
            for j in range(n):
                if (i>>j) & 1 ==1: temp.append(nums[j])
            ans.append(temp[:])
        return ans
```