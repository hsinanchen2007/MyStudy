### 解题思路
题目要求到达最后一个元素，那么倒不了的就是False
能到的平均最差情况，就是分摊下来，一步一步走到
言外之意，只要中间有一步过不去那就失败
分析这种情况：
1、nums[i]=0
2、上一步的最远距离无法跨过去

### 代码

```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        lenghth=len(nums)
        index=0
        for i in range(lenghth):
            if index>=lenghth-1: return True
            if nums[i]==0 and index<=i: return False
            index=i+nums[i] if index<i+nums[i] else index

```