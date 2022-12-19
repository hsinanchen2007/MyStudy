### 解题思路

参考题解：
- [官方](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/zhu-zhuang-tu-zhong-zui-da-de-ju-xing-by-leetcode/)（建议先看官方题解，跟着思路一步步走，把握题目的点和脉络，有看不懂的先跟着走，后面再找其他大佬的分析。）
- 力友“[powcai](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/zhao-liang-bian-di-yi-ge-xiao-yu-ta-de-zhi-by-powc/)”（然后再参考官方题解之后的大佬们的见解，他们给出的往往是能够帮助我们解决思路上某个地方有困惑的点）

个人始终建议，要先把握脉络，不能为了解题而解题，向各位大佬们学习！


感谢！

### 代码

```python3
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        heights = [0] + heights + [0]
        res = 0
        for i in range(len(heights)):
            # print(stack)
            while stack and heights[stack[-1]] > heights[i]:
                tmp = stack.pop()
                res = max(res, (i - stack[-1] - 1) * heights[tmp])
            stack.append(i)
        return res

# 作者：powcai
# 链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/zhao-liang-bian-di-yi-ge-xiao-yu-ta-de-zhi-by-powc/
# 来源：力扣（LeetCode）
# 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```