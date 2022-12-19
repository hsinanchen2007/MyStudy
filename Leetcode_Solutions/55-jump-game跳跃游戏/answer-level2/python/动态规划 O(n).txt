![image.png](https://pic.leetcode-cn.com/4bbbd9542bae1a86c264ff86aac32a1c851c7d8de26ec67ee915beef72b71d4e-image.png)
![Snipaste_2020-03-07_21-57-47.png](https://pic.leetcode-cn.com/1cfa53f5d80af2536b79fef06d2610c32c19d722474b367b483f0b0cf85586ad-Snipaste_2020-03-07_21-57-47.png)

### 解题思路
采用动态规划的思想寻找可以从0节点跳跃的最远距离
举例说明：
nums = [2, 2, 0, 1, 4]
设置初始最远跳跃距离 max_distance 是 0
将nums数组遍历一遍，找到最远跳跃距离是len(nums)-1即可(之所以
减1是因为这里算跳跃距离是当前位置+当前位置的值，当前位置是从0
开始搜索的，但这样计算的条件是该位置在可跳跃的位置上，也就是
该位置的索引小于等于max_distance, 即该位置包含在从0节点可以
跳跃的最远距离范围之内)
第一步：
    位置为0，值是2，
    由于 0 <= max_distance，
    所以 max_distance = max(max_distance, 0+2) = 2
第二步：
    位置为1，值是2
    由于 1 <= max_distance，
    所以 max_distance = max(max_distance, 1+2) = 3
第三步：
    位置为2，值是0
    由于 2 <= max_distance，
    所以 max_distance = max(max_distance, 2+0) = 3
第三步：
    位置为3，值是1
    由于 3 <= max_distance，
    所以 max_distance = max(max_distance, 3+1) = 4
    由于此时 max_distance >= len(nums)-1
    所以返回 True

这里的动态规划跟我以前做过的题不同，并没有维护一个列表，但是确实是动态规划，
因为维护了max_distance这个值，根据这个值的情况来确定当前的搜索情况该怎么处
理，才会使得时间复杂度只有O(n)。

### 代码

```python
class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) == 1:
            return True
        max_distance = 0
        for i in range(len(nums)-1):
            if i <= max_distance:
                max_distance = max(max_distance, i+nums[i])
            if max_distance >= len(nums)-1:
                return True
        return False

```