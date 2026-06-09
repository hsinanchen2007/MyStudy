### 解题思路
这是[78题](https://leetcode-cn.com/problems/subsets/)的升级，就是多了重复元素的筛除。
首先对整个列表进行一个排序，把重复的元素排到一起，相同元素的第一个按照正常迭代计算，从第二个开始就要注意重复。此时，用一个pre来存储前面第一个数迭代后的结果，后面的每一个重复的数都分别取和这个pre组合，而不是从整个列表的第一个元素开始组合。

### 代码

```python3
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res=[[]]
        pre=[]
        n=len(nums)
        for i in range(n):
            if(i>0 and nums[i]==nums[i-1]):
                pre=[[nums[i]]+num for num in pre]
            else:
                pre=[[nums[i]]+num for num in res]
            res+=pre
        return res
```