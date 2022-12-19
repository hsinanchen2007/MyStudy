### 解题思路 对于每个柱子，我们需要找它的两边第一个比它小的元素。因此，每个元素入栈时。如果比栈顶元素小，就是不满足，所以此时用单调递增栈（递减时我们想触发不满足处理它）。这里是是从方便记忆的代码的角度考虑。不满足时最新想要加入的（但加不成的）自然是右边第一个比他小的元素。不过，这个栈的神奇之处在于：弹出一个元素之后，栈顶就是左边第一个小于弹出元素的元素。小于我是理解的单调递增栈嘛。但是第一个就难以理解了，现在就在此记住吧，有大佬的话可以详细大家证明一下。
为什么就不要追究了？
### 代码
[这里抄来的代码](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/zhao-liang-bian-di-yi-ge-xiao-yu-ta-de-zhi-by-powc/)

```python
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        heights = [0] + heights + [0]
        res = 0
        for i in range(len(heights)):
            #print(stack)
            while stack and heights[stack[-1]] > heights[i]:
                tmp = stack.pop()
                res = max(res, (i - stack[-1] - 1) * heights[tmp])
            stack.append(i)
        return res

```