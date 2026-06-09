### 解题思路
用递归完成，更易于理解，每次的选择都是根据这次选择的结果来进行的
而只有当遍历完整个数组，或者已经凑齐目标值(或者已经大于目标值)时，才知道结果

### 代码

```python3
import functools
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s=sum(nums)
        if s%2:
            return False
        target=s//2
        n=len(nums)

        #用带记忆化的递归，current表示当前总和，i表示正在抉择第i个数
        @functools.lru_cache(None)
        def dfs(current,i):
            if i>=n or current>target:
                return False
            if current==target:
                return True
            #加入第i个数或者不加入第i个数，若有一个结果为True，则返回True，都不满足则返回False
            return dfs(current+nums[i],i+1) or dfs(current,i+1)

        #初始情况时current即当前总和为0，从第一个数开始抉择
        return dfs(0,0)
```