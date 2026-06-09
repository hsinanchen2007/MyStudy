## 解题分析
首先在栈中，pop和push操作都是操作栈顶的元素，时间复杂度本来就是O(1)，是满足题目要求的；
min方法是普通的栈操作里面没有的，取最小的元素，我们可以依次遍历栈中的元素，比较出最小值，但是这样的时间复杂度是O(n)，明显不符合题目的要求；

我们的做法就是，维护一个值栈和一个最小值栈，值栈每次都是正常的压入和弹出数据，而最小值栈值压入最小值，这样的话，每次，需要调用min函数的时候我们只需要看一下最小值栈的栈顶元素是什么即可；

而元素弹栈，即调用pop方法的时候，我们需要从值栈中返回元素，再看一下最小值栈中的元素是不是等于值栈中弹出的元素，如果是的话，最小值栈也要弹栈栈顶的元素，这样才能保持最小值栈中的栈顶元素是值栈中的最小元素；

这里有一个细节，就是最小值栈中压入元素的时候，是压进来的元素小于等于目前的最小值栈的栈顶元素，等于也必须要压入，因为值栈中有两个最小值的话，一旦一个弹栈了，最小值栈也要跟着弹栈一个，但是此时人家的最小值还是那个值，所以我们的最小值栈的最小值的个数也要和值栈保持一致；

## 代码
ps：这里笔者使用的jdk为1.8、Python3.7版本

- java实现
```java
class MinStack {
    /**
     * 数值栈
     */
    Stack<Integer> valueStack;
    /**
     * 最小值栈
     */
    Stack<Integer> minStack;

    public MinStack() {
        valueStack = new Stack<>();
        minStack = new Stack<>();
    }

    public void push(int x) {
        valueStack.push(x);
        if (minStack.empty() || minStack.peek() >= x) {
            minStack.push(x);
        }
    }

    public void pop() {
        if (valueStack.pop().equals(minStack.peek())) {
            minStack.pop();
        }
    }

    public int top() {
        return valueStack.peek();
    }

    public int min() {
        return minStack.peek();
    }
}
```

- Python实现

```python
class MinStack:
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.value_stack = []
        self.min_stack = []

    def push(self, x: int) -> None:
        self.value_stack.append(x)
        if len(self.min_stack) == 0 or x <= self.min_stack[-1]:
            self.min_stack.append(x)

    def pop(self) -> None:
        if self.value_stack.pop(-1) == self.min_stack[-1]:
            self.min_stack.pop(-1)

    def top(self) -> int:
        return self.value_stack[-1]

    def min(self) -> int:
        return self.min_stack[-1]
```
