### 解题思路
和78题的解题思路差不多
有两个关键点：首先nums要排序；其次要判断是否已经存在结果集中。

### 代码

```python
class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums: return []
        nums.sort()
        ans=[[]]
        for n in nums:
            length=len(ans)
            for i in range(length):
                if ans[i]+[n] not in ans:
                    ans.append(ans[i]+[n])
        return ans
```