看到需要保持最小数，自然而然想到用堆，可以保证入栈、出栈均为O(log(n))。不过这里要求最小栈有个pop的方法，故还需要对堆进行特定元素的删除操作，由于Python的heapq不具备删除操作（不过可以自行调用_siftdown），所以这里考虑采用辅助数组来记录排序数组，这样利用二分搜索插入和删除也同样可以保持O(log(n))。二分搜索采用bisect库简化代码。

```
import bisect
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        
        Space: O(2n)
        """
        self.stack = []
        self.sorted_stack = []
        

    def push(self, x: int) -> None:
        """
        Time: O(log(n))
        """
        self.stack.append(x)
        bisect.insort(self.sorted_stack, x)
        

    def pop(self) -> None:
        """
        Time: O(log(n))
        """
        del self.sorted_stack[bisect.bisect(self.sorted_stack, self.stack[-1]) - 1]
        del self.stack[-1]
        

    def top(self) -> int:
        return self.stack[-1]
        

    def getMin(self) -> int:
        return self.sorted_stack[0]
```
