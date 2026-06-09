
首先把height和weight组合起来形成[(h,w), ...], 称为hw
然后对hw进行排序，首先比较h大小，其次比较w大小
然后遍历hw，同时更新一个栈stack：
- 如果栈是空的，或者stack最后一个(last_h,last_w)的last_w小于当前的w，而last_h也小于当前h，所以可以直接把这个元素添加到stack中
- 否则说明last_w > w, 这种情况下，我们可以用（h, w)去替换stack中weight刚好比w大的元素，可以用二分搜索去找到这个位置，因为替换之后不影响结果的长度
最后stack的长度就是结果


```
class Solution:
    def bestSeqAtIndex(self, height: List[int], weight: List[int]) -> int:
        hw = sorted([(h, w) for h, w in zip(height, weight)])
        stack = []
        for h, w in hw:
            if not stack or stack[-1][0] < w:
                stack.append((w, h))
            else:
                index = bisect.bisect_left(stack, (w, 0))
                stack[index] = (w, h)
        return len(stack)
```