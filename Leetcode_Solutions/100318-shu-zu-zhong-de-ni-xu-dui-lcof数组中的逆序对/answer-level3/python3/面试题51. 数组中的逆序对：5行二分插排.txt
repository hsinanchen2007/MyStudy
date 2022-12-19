### 解题思路

理论上没有归并排序快，插入比较费时。
测试过Python里面`q[i: i] = [val]`会比`q.insert(i, val)`快一些。

### 代码

```python []
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        q, ans = [], 0
        for n, num in enumerate(nums):
            ans += n - (i := bisect.bisect(q, num))
            q[i: i] = [num]
        return ans
```