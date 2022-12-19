Py3双百，用一个list去模拟栈的真实情况，和poped对比去挨个消除，看能不能清空poped
```python
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        tmp_stack = list()

        pointer = 0

        for i in pushed:
            tmp_stack.append(i)
            
            # 这个while用来模拟（连续）pop的过程，一直符合一直pop
            while tmp_stack[-1] == popped[pointer]:
                tmp_stack.pop()
                pointer += 1
                if len(tmp_stack) == 0:
                    break
        return len(popped) == pointer

```
