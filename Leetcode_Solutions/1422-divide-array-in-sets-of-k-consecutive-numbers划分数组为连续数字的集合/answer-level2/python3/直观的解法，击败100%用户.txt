### 解题思路
排序之后，每次从当前最小的数n开始，检查并pop出n,n+1,n+2...n+k-1。
使用dictionary将每个数的查询时间限制在O（1）。因此查询所用时间为O(N)，考虑到排序复杂度为O（n log n），因此最坏复杂度为O（n log n）

执行用时 :
180 ms
, 在所有 Python3 提交中击败了
100.00%
的用户
内存消耗 :
27.1 MB
, 在所有 Python3 提交中击败了
100.00%
的用户

### 代码

```python3
from collections import defaultdict
class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        if len(nums)% k!=0:
            return False
        nums.sort()
        nums_dict = defaultdict(int)

        for x in nums:
            nums_dict[x]+=1

        while nums_dict:
            for first_num in nums_dict:
                break 
            for x in range(first_num,first_num+k):
                if x not in nums_dict:
                    return False
                nums_dict[x] -=1
                if nums_dict[x]<=0:
                    nums_dict.pop(x)
        return True
```