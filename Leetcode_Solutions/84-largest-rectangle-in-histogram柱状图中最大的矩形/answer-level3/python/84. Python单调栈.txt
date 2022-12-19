### 解题思路
（1）为什么可以使用单调栈？因为以某个柱体为中心，以它的高度h为高度的矩形所组成的块的高度都应该>=h，所以这道题实际上也是一个找邻域内的边界的问题。（比如之前的接雨水）
（2）如何确定使用单调递增栈还是单调递减栈？单调栈在发生非设置顺序的时候对栈中元素进行处理，比如对于单调递增栈来说，当新高度h<栈顶元素高度h'时进行处理，显然这道题是选择单调递增栈，因为如果发生上述情况，说明所维持的矩形的面积会发生改变，因为短板效应。
（3）栈中元素记录什么？栈中元素应该记录的是(当前高度h, 包括自身左边连续的大于等于h的木板数量num)，这样可以保证在弹栈的时候在该元素之前弹栈的木板数量都是大于等于它的，换句话说也就是num+弹栈的木板数量。

### 代码

```python
class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        stack = []
        heights.append(0) # 为了最后能够使栈清空
        max = 0
        for h in heights:
            if len(stack) == 0 or h > stack[-1][0]:
                stack.append((h, 1)) # 其中这个1代表包括自身左边有几个大于等于当前高度的柱体
            else:
                num = 0
                while len(stack) != 0 and h <= stack[-1][0]:
                    num += stack[-1][1]
                    temp = num * stack[-1][0]
                    if temp > max:
                        max = temp
                    del stack[-1]
                stack.append((h, num + 1))
        return max
```