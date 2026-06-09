# 先讨论一种特殊情况，如果我们知道最右边的柱子是最高的，那么我们怎么计算这道题呢？**我们只需要从左边第一个非零高度的柱子开始往右，找到下一个等于或者高于它的柱子**，计算它们之间水的容量，然后以找到的柱子为左边界，继续找下一个等于或者高于它的柱子，以此类推。我们知道最右边的柱子是最高的，因此最后必能得出正确结果。就把这个问题称为“阶梯型存水问题”吧。😂
# ![WeChat Screenshot_20200317232544.png](https://pic.leetcode-cn.com/e0ad854b461ae0ff7415f61e06950a8f1c1e22812e85f90dec5c4606d561f86c-WeChat%20Screenshot_20200317232544.png)

# 现在继续来看接雨水问题，上面我们之所以能从左边一直往右走，是因为我们知道水桶的高度上界在最右边，因此我们只需要关心左边的“短板”。因为短板决定最终盛水的容量。给我们的启发就是“计算的方向应该始终从短板往长板！”
# 接着我们看短板走一步有什么效果。如果该柱子低于短板，由于短板决定水的高度，因此我们能计算出该根柱子所能储存的水量``短板高度 - 该根柱子高度``,如果该柱子高于短板或和短板一样高，该柱子也存不了水，此时以该柱高度更新一下短板高度。

# 以上可以得出两个要点：

# **1. 从短板往长板走是安全的
# 2. 每次走一步是安全的。**

# 简单来说就是一个“胖桶”逐渐变“瘦”的过程。

# 代码如下：
# ```
class Solution:
    def trap(self, height: List[int]) -> int:
        rst = 0
        # 处理边界情况
        if not height: return rst
        # 左边及右边“桶壁” ---- 起挡水作用的柱子
        max_left, max_right = height[0], height[-1]
        # 内部柱子
        left, right = 1, len(height) - 2
        # 处理完内部所有柱子
        while right >= left:
            # 如果“左桶壁”低于“右桶壁”，“左桶壁”为短板
            if max_left < max_right:
                # 如果该“桶壁”比当前所处理的柱子高，则当前柱子可储水，更新结果。
                if max_left > height[left]:
                    rst += (max_left - height[left])
                # 否则更新左桶壁高
                else:
                    max_left = height[left]
                # 处理完一根柱子，前进一步。
                left += 1
            # 右“桶壁”是短板
            else:
                # 该“桶壁”比当前所处理的柱子高，则当前柱子可储水，更新结果。
                if max_right > height[right]:
                    rst += (max_right - height[right])
                # 否则更新右桶壁高
                else:
                    max_right = height[right]
                # 处理完一根柱子，前进一步。
                right -= 1
        return rst
# ```
