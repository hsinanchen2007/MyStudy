### 解题思路
**思路：**
     维护一个单调递增栈，用来存储柱状图中各个柱子的高度。只要当前元素比栈顶元素大就将当前元素的下标入栈；当前元素比栈顶元素小就挨个计算面积。
**具体实现：**
     **·** 使用栈stack来存储柱子的索引下标。
     **·** 遍历数组：
            。当栈非空且栈顶元素大于等于当前遍历的元素（heights[stack[-1]] >= heights[i]）时，意味着可以计算面积了
                **·** 将栈顶元素弹出，并用临时变量last保存这个弹出的值，last表示下标
                **·** 若弹出后栈不为空，就要计算宽度了，width = i - stack[-1] - 1
                    （i表示当前遍历到的下标，stack[-1]表示上面的栈顶元素弹走后现在的栈顶元素）
                **·** 若弹出后栈为空，宽度width = i
                **·** 计算面积，求最大值maxArea = max(maxArea, heights[last] * width)
            。将当前索引下标入栈（因为要计算宽度）
     **·** 返回最大面积maxArea。

![2.png](https://pic.leetcode-cn.com/f8a90083f777dcf52d6734c641a33b29ad308398b55d3dd2bf244cf6c02d6f27-2.png)

### 代码

```python3
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        heights.append(0)
        stack = []
        maxArea = 0
        for i in range(0, len(heights)):
            while stack and heights[stack[-1]] >= heights[i]:
                last = stack.pop()
                if stack:
                    width = i - stack[-1] - 1
                else:
                    width = i
                maxArea = max(maxArea, heights[last] * width)
            stack.append(i)
        return maxArea
```