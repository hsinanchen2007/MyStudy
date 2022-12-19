**解题思路：遍历push列表，将列表中的数依次加入push_stack，同时与popped中的元素对比，如果遇到和pop中相等的元素则将其放入pop_stack，并将指向popped元素的指针+1；遍历结束后，将push_stack中的数依次弹出放入pop_stack，最后按照栈尾→栈顶的顺序与popped中的元素进行比对**


    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        #定义用于push和pop操作的栈：
        push_stack, pop_stack = [], []
        
        #定义可能需要提前pop的数的索引
        index = 0
        
        for i in pushed:
            if i == popped[index]:
                pop_stack.append(i)
                index += 1
                #对比栈中元素和popped中的元素，直到不相等或栈为空
                while len(push_stack) != 0 and push_stack[-1] == popped[index]:
                    pop_stack.append(push_stack[-1])
                    push_stack.pop()
                    index += 1
            else:
                push_stack.append(i)
        
        #将push_stack中的数依次弹出并放入pop_stack:
        while len(push_stack) != 0:
            pop_stack.append(push_stack[-1])
            push_stack.pop()
        
        #依次对比pop_stack和popped列表中元素，如果不一致，返回False
        for index, value in enumerate(pop_stack):
            if value != popped[index]:
                return False
        return True