### 解题思路
自己也想到了用栈进行操作，无奈逻辑不清晰，敲不出来。。。
以下是参考的[官方题解](https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/)，条分缕析，感谢！


- 若当前元素的高度height[cur]小于等于栈顶元素对应的高度height[stack.top]，则将其索引入栈；
- 若height[cur] > height[stack.top], 则将栈顶元素弹出，记为top；
- 此时，我们要对索引在[top, cur]之间的所有柱子进行填充，填充的高度：
  - boudnHeight = min(height[stack.top], height[cur])，
  - 其中stack.top是弹出top之后的那个栈顶元素；
- 填充的目的，是为了计算当前高度下的蓄水量，且不会影响栈内其他元素与之后的柱子高度之间的蓄水量的计算；
- 这样，我们可以计算出，填充所跨越的柱子数量:
  - distance = cur - stack.top - 1；
  - 其中stack.top是弹出之后的那个栈顶元素；
- 由此，我们可以记录下当前高度差下的蓄水量，并将其添加到最终的结果中即可；
  - ans += distance*boundHeight

以上，使用栈和填充的策略，分步进行蓄水量的计算，且不影响其他更高柱子的蓄水量计算，厉害，菜鸟表示还要继续学习才是


### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        lgth = len(height)
        if lgth < 1:
            return 0

        stack = []
        cur = 0
        ans = 0
        while cur < lgth:
            while stack and height[cur] > height[stack[-1]]:
                top = stack[-1]
                stack.pop(-1)
                if not stack:
                    break
                
                distance = cur - stack[-1] - 1
                bound_height = min(height[cur], height[stack[-1]]) - height[top]
                ans += distance*bound_height

            stack.append(cur)
            cur += 1
            
        return ans
```