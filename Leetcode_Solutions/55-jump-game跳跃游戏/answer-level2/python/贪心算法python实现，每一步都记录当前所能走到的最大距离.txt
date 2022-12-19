### 解题思路
此处撰写解题思路
也不是啥算法大佬，巨佬勿笑。就是从nums[0]到nums[lenth-2]，每一步都记录当前能走到的最大距离.
nums[length-1]这一步其实就不用管了，具体值是多少对结果也没影响。时间复杂度O（n）
### 代码

```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if not nums:
            return False
        l = len(nums)
        if l == 1:
            return True
        maxEdge=0
        for i in range(l-1):
            maxEdge = max(i+nums[i],maxEdge)
            if i == maxEdge and nums[i]==0:
                break;

        return maxEdge >= l-1
     


```