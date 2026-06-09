### 解题思路
单调栈特别适合解决那些，两头大小决定中间值的大小的题。
![image.png](https://pic.leetcode-cn.com/ab678845e53e42464f684c1f876c061901029e9dcef7219ad2fb5c7388b4730f-image.png)

题的关键点在于：
    以B点为高的矩形的最大宽度为， 从a到c， 其中a，c分别为B左边和右边第一个小于B的元素。
    单调栈的特点在于：
    当遇见大数的时候， 压入堆栈，等待之后处理。
    当遇见小数c的时候，意味着大数b的右边界c已经确定了。
    这时候开始pop， 而以被pop出来的值（b）为高度的矩形的左右边界需要被确定。
    其右边界就是当前的小数。即为c。左边界是堆栈下一层的元素，因为下一层的元素一定比当前小。且是第一小的元素。这时候a也确定了。
    则以被pop出来的数为高度的矩形是 (c - a - 1) * pop()， 这里pop() == b



### 代码

```python
class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        stack = []
        heights = [0] + heights + [0]
        res = 0
        for i in range(len(heights)):
            # print i, stack
            while stack and heights[stack[-1]] > heights[i]:
                tmp = stack.pop()
                res = max(res, (i - stack[-1] - 1) * heights[tmp])
                # print res
            stack.append(i)
        return res



```