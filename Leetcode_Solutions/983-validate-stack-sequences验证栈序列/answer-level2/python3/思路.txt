### 解题思路
用一个队列来存储pop数组，遍历push数组，将每个元素push到栈中，通过对比栈的最后一个元素是否等于队列的第一个元素，不相等的话继续push入栈中对比，当有相同时出栈和出队列，如果栈为空，说明符合顺序规定

### 代码

```python3
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        queue_order = popped
        stack = []
        for i in range(len(pushed)):  # 遍历push的元素
            stack.append(pushed[i])  # 将每个元素放入栈中
            while len(stack) > 0 and stack[-1] == queue_order[0]:  # 栈的长度>0 and 栈的最后一个元素等于队列的第一个元素
                stack.pop()  # 栈删除最后一个元素
                queue_order.pop(0) # 队列删除第一个元素
        if len(stack) > 0:
            return False

        return True
```