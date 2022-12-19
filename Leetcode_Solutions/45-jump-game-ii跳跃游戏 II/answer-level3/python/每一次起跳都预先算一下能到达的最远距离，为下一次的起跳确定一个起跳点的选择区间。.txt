### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        贪心算法
        每一次起跳都预先算一下能到达的最远距离，为下一次的起跳确定一个起跳点的选择区间。
        """
        steps = 0
        begin = 0
        end = 0 # [begin,end] 为可选择的起跳点区间，第一次起跳只能选第0个
        maxPos = 0
        n = len(nums)
        while end<n-1:
            for i in range(begin, end+1):
                maxPos = max(maxPos, i+nums[i])
                # 本次起跳范围遍历完
                if i == end:
                    steps+=1
            # 确定下一次起跳点区间
            begin = end+1
            end = maxPos
        return steps
```
广泛参考了大佬们的解题思路，枯了