倒序遍历pushed，  每次查看pushed的元素在popped中的位置之后的元素，是否是降序排列。
```
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:

        length = len(popped)
        push_index = length -1
        while push_index>0:
            pop_index = popped.index(pushed[push_index])
            push_index -= 1
            if length - pop_index < 2:
                length -=1
            else:
                for i in range(pop_index, length-1):
                    if pushed.index(popped[i]) < pushed.index(popped[i+1]):
                        return False
                length = pop_index
            
        return True
```
