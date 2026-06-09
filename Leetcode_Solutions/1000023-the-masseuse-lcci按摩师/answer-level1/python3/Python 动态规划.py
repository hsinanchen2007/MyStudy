![image.png](https://pic.leetcode-cn.com/e3e5be896dabb6cc1c7e01fbac0bfdee548f56e24e5b5b819b0d3d7be9f5fecd-image.png)

涉及这种依赖之前的选择的一般都是动态规划问题
状态：用二维数组表示，dpTable[i][0] 表示第i个元素且未预约的总时长，dpTable[i][1]表示第i个元素预约的总时长
状态转移方程：dpTable[i][0] = max(dpTable[i-1][0], dpTable[i-1][1]), 取前一个位置内最大的即可
dpTable[i][1] 这个就要保证前一个位置并没有预约，否则会有冲突，dpTable[i][1] = dpTable[i-1][0] + nums[i]

不过我们可以看到，实际上状态转移只用了前一列的dpTable， 可以修剪以减小存储空间
代码如下：
```python
 class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums:
            return 0
        # dpTable剪枝
        dpTable = [0,0]
        # 初始状态
        dpTable[1] = nums[0]
        for i in range(1, len(nums)):
            prevDp0 = dpTable[0]
            dpTable[0] = max(dpTable[0], dpTable[1])
            dpTable[1] = prevDp0 + nums[i]
        return max(dpTable[0], dpTable[1])

```