
这是一个非常典型的利用单调栈来解决 顺序和大小综合问题的题。
单调栈特别适合解决那些，两头大小决定中间值的大小的题。

因为单调栈中，以单调增栈为例。
设栈顶元素为 b， 栈顶第二个元素为a，自然有 a < b （因为堆栈越往上越大）
这时候， 若c出现，且c小于b， 那么b的左右第一个比b小的两个元素就找到了，分别是a和c，b在中间最大。 
这时候你可以处理b，并重新整理堆栈，使其保持递增。
若c大于b，那c入栈，继续循环就行了。
最后清理堆栈

单调栈的结构：

```
for i  in  list:
    while i is not empty and stack[-1] > i: 先调整位置。
        stack.pop()
    stack.append(i)  #当前元素无论如何也要放进去，不同的只是需不需要pop来调整位置
```

这个题的关键点在于：
**以B点为高的矩形的最大宽度为， 从a到c， 其中a，c分别为B左边和右边第一个小于B的元素。**
单调栈的特点在于：
当遇见大数的时候， 压入堆栈，等待之后处理。
当遇见小数c的时候，意味着大数b的右边界c已经确定了。
这时候开始pop， 而以被pop出来的值（b）为高度的矩形的左右边界需要被确定。
其右边界就是当前的小数。即为c。左边界是堆栈下一层的元素，因为下一层的元素一定比当前小。且是第一小的元素。这时候a也确定了。
则以被pop出来的数为高度的矩形是 (c - a - 1) * pop()， 这里pop() == b

这里细节需要注意的是，
1. 栈底要垫上-1，表示栈底。
2. 循环结束，要清理堆栈。此时所有栈中继续存放的元素的**右边界c都是结尾len(height)-1**


```python
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = [-1]
        max_res = 0
        for i in range(len(heights)):
            while len(stack) > 1 and heights[i] <= heights[stack[-1]]:
                max_res = max(max_res, heights[stack.pop()] * (i - stack[-1] - 1))  
            stack.append(i)
        for i in range(len(stack)-1):
            max_res = max(max_res, heights[stack.pop()]*(len(heights)-1-stack[-1]))
        return max_res
```
