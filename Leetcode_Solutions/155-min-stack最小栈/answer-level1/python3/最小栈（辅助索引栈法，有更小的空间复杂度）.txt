# 应用两个栈：
stack：当做普通栈使用
minstack：存放最小值对应的索引，可以避免存放连续相同的最小值时minstack占用过多空间

# 举个例子：
当存放顺序为[1,1,1,1,1]时，stack=[1,1,1,1,1]
1）若minstack存放当前stack的最小值，则有minstack=[1,1,1,1,1]
2）若minstack存放当前stack的最小值对应索引时，则有minstack=[0]

# 详解各操作：
1）push(x)
    stack肯定要入，主要讨论minstack入栈情形有两种：
    一是minstack为空，第一个入栈元素一定是最小值
    二是 x < getMin()，即当前栈内元素最小值需要更新

2）pop()
    stack肯定要出，主要讨论minstack出栈情形。
    当且仅当出栈元素是最小值时，才需要更新minstack，由于minstack中存放最小值元素对应的索引，那么当
    栈顶元素的索引等于minstack栈顶时，minstack才会出栈。
    即 len(stack)-1==minstack[-1]

3）top()
    这个没什么好说的，返回最后一个元素即可。stack[-1]

4）getMin()
    由上面介绍可知，直接返回minstack栈顶元素作为索引指向的stack中元素。
    即stack[minstack[-1]]

下面附代码：
```python []
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack=[]
        self.minStack=[]

    def push(self, x: int) -> None:
        if len(self.minStack)==0:
            self.minStack.append(len(self.stack))
        elif x<self.getMin():
            self.minStack.append(len(self.stack))
        self.stack.append(x)

    def pop(self) -> None:
        if self.minStack[-1]==len(self.stack)-1:
            self.minStack.pop()
        self.stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.stack[self.minStack[-1]]

```
时间复杂度为O(1)
空间复杂度为O(n)【P.s 该空间远小于元素个数n】