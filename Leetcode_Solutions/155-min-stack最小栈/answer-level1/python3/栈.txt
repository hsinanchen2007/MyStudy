## 思路:

思路一:使用两个栈

一个栈记录 压入元素

一个栈记录 最小元素

思路二 : 使用一个栈 [^1]

当有更小元素进入栈中, 把先前最小值压入栈中

## 代码:

```python
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min_num = []
        

    def push(self, x: int) -> None:
        self.stack.append(x)
        if len(self.min_num) == 0 or self.min_num[-1] >= x:
            self.min_num.append(x)
        

    def pop(self) -> None:
        if self.stack:
            tmp  = self.stack.pop()
            if self.min_num[-1] == tmp:
                self.min_num.pop()
            return tmp
        

    def top(self) -> int:
        if self.stack:
            return self.stack[-1]
        

    def getMin(self) -> int:
        return self.min_num[-1]
```

思路二:

```python []
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.cur_min = float("inf")
        

    def push(self, x: int) -> None:
        if x <= self.cur_min:
            self.stack.append(self.cur_min)
            self.cur_min = x
        self.stack.append(x)
        

    def pop(self) -> None:
        if self.stack.pop() == self.cur_min:
            self.cur_min = self.stack.pop()
        

    def top(self) -> int:
        return self.stack[-1]
        

    def getMin(self) -> int:
        return self.cur_min
```



```java []
class MinStack {
    /**
     * initialize your data structure here.
     */
    Deque<Integer> stack = new LinkedList<>();
    int min = Integer.MAX_VALUE;

    public MinStack() {
    }

    public void push(int x) {
        if (min >= x) {
            stack.push(min);
            min = x;
        }
        stack.push(x);
    }

    public void pop() {
        if (stack.pop() == min) min = stack.pop();
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return min;
    }
}
```





[^1]: <https://leetcode.com/problems/min-stack/discuss/49014/Java-accepted-solution-using-one-stack>