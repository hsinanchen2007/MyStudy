```
class Solution(object):
    def dailyTemperatures(self, T):
        """
        :type T: List[int]
        :rtype: List[int]
        """
        if not T:
            return
        stack = []
        n = len(T)
        res = [0] * n
        # stack.append((0, T[0]))
        def peek(stack):
            if stack:
                return stack[len(stack)-1]
        for index, value in enumerate(T):
            if index == 0:
                stack.append((0, T[0]))
                continue
            if not stack:
                # 入栈
                stack.append((index, value))
            while stack:
                # 获得当前栈顶元素，不出栈
                peek_value = peek(stack)
                if peek_value[1] < value:
                    # 如果当前栈顶元素的温度小于当前元素的温度，则将栈顶元素弹出栈，所需要的天数为当前index和弹出元素的tmp_index的差
                    tmp = stack.pop()
                    tmp_index = tmp[0]
                    # 将对应tmp_index位置的所需天数添加到res中
                    res[tmp_index] = index - tmp_index
                    # 将当前index的元祖入栈,在这里入栈是错误的，因为当前栈顶元素弹出后，新的栈顶元素有可能还小于当前温度，所以不能将当前温度压入栈
                    # stack.append((index, value))
                if peek_value[1] >= value:
                    # 如果当前栈顶元素的温度大于当前元素的温度，将当前温度的元祖入栈
                    stack.append((index, value))
                    break
            # 当遍历栈顶元素不小于当前温度时，将当前温度入栈
            stack.append((index, value))
        return res
```
