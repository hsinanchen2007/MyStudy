### 解题思路
需要复习

### 代码

```python3
class TripleInOne:

    def __init__(self, stackSize: int):     # stackSize是栈的大小
        self.stack = [0 for i in range(stackSize * 3)]  # 初始化三倍stackSize的列表存放3个栈
        self.ptr1 = 0   # 第一个栈的指针，起始位置是列表的0位置
        self.ptr2 = 0 + stackSize    # 第二个栈的指针，起始位置是列表的stackSize位置
        self.ptr3 = 0 + 2 * stackSize  # 第三个栈的指针，起始位置是列表的2*stackSize位置
        self.stackSize = stackSize  # 每一个栈的大小

    def push(self, stackNum: int, value: int) -> None:
        if stackNum == 0 and 0 <= self.ptr1 < self.stackSize:   # 往第一个栈加入元素
            self.stack[self.ptr1] = value  
            self.ptr1 += 1
        elif stackNum == 1 and self.stackSize <= self.ptr2 < 2 * self.stackSize:  # 往第二个栈加入元素
            self.stack[self.ptr2] = value
            self.ptr2 += 1
        elif stackNum == 2 and 2 * self.stackSize <= self.ptr3 < 3 * self.stackSize:  # 往第三个栈加入元素
            self.stack[self.ptr3] = value
            self.ptr3 += 1

    def pop(self, stackNum: int) -> int:  # pop() 返回栈顶元素，并在进程中删除它
        if stackNum == 0 and 0 < self.ptr1 <= self.stackSize: # 从第一个栈删除一个元素
            self.ptr1 -= 1
            return self.stack[self.ptr1]
        elif stackNum == 1 and self.stackSize < self.ptr2 <= 2 * self.stackSize: # 从第二个栈删除一个元素
            self.ptr2 -= 1
            return self.stack[self.ptr2]
        elif stackNum == 2 and 2 * self.stackSize < self.ptr3 <= 3 * self.stackSize:  # 从第三个栈删除一个元素
            self.ptr3 -= 1
            return self.stack[self.ptr3]
        return -1

    def peek(self, stackNum: int) -> int:  # peek() 返回栈顶元素，但不在堆栈中删除它
        if stackNum == 0 and 0 < self.ptr1 <= self.stackSize:  # 返回第一个栈的栈顶元素
            return self.stack[self.ptr1-1]
        elif stackNum == 1 and self.stackSize < self.ptr2 <= 2 * self.stackSize: # 返回第二个栈的栈顶元素
            return self.stack[self.ptr2-1]
        elif stackNum == 2 and 2 * self.stackSize < self.ptr3 <= 3 * self.stackSize: # 返回第三个栈的栈顶元素
            return self.stack[self.ptr3-1]
        return -1

    def isEmpty(self, stackNum: int) -> bool: 
        if stackNum == 0 and self.ptr1 == 0:
            return True
        elif stackNum == 1 and self.ptr2 == 0 + self.stackSize:
            return True
        elif stackNum == 2 and self.ptr3 == 0 + 2 * self.stackSize:
            return True
        return False

# 作者：EthanNING

# Your TripleInOne object will be instantiated and called as such:
# obj = TripleInOne(stackSize)
# obj.push(stackNum,value)
# param_2 = obj.pop(stackNum)
# param_3 = obj.peek(stackNum)
# param_4 = obj.isEmpty(stackNum)
```