公众号连载leetcode题解，欢迎关注。

![](https://pic.leetcode-cn.com/2a15d78b4b977527a4d95f2bb238db8c82b7d133878dbf168b4b972271818c58.jpg)


题目汇总： [leetcode](http://flypython.com/leetcode/) 


#### 思路

根据题意，我们只能使用队列的基本操作，队列因为是先进先出，要实现先进后出的栈，常见的解法方法是使用两个队列。

假设有q1，q2两个队列，我们初始化队列。


```
from collections import deque
class MyStack:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q1 = deque()
        self.q2 = deque()
```

##### push

![](https://pic.leetcode-cn.com/5c7f7e09f66a402e741452d055c6739d52bb1e332252e7f07b1667e4d7eb5ed1.jpg)

压入栈时，加入到q1的末尾，那么q1末尾的元素就是栈顶元素

```
    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q1.append(x)

```

时间复杂度：O(1)
空间复杂度：O(1)

#### pop
![](https://pic.leetcode-cn.com/28e2975a945e35781d2381dd7ac7b03af380a328408f2518f18de39318e5b81c.jpg)


我们需要弹出栈顶元素，也就是q1最后的元素，队列只能是先进先出，我们得用q2把q1出队的元素装着，最后一个出队元素就是栈顶元素。

```
    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        while len(self.q1) > 1:
            self.q2.append(self.q1.popleft())
        tmp = self.q1.popleft()
        self.q2,self.q1 = self.q1, self.q2
        return tmp
        
```
时间复杂度：O(n)

#### empty

判断是否为空，只需要判断q1

```
    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """

        return not bool(self.q1)


```
#### top

取栈顶元素。这里其实可以优化，我们可以在push时保留一个变量，不过记得在pop时需要替换栈顶元素。

```
    def top(self) -> int:
        """
        Get the top element.
        """
        while len(self.q1) != 1:
            self.q2.append(self.q1.popleft())
        tmp = self.q1.popleft()
        self.q2.append(tmp)
        self.q2,self.q1 = self.q1,self.q2
        return tmp

```

使用两个队列，还有另外一种思路。我们可以在入栈时，先把新元素在q2入队，把所有的q1元素全部出队，在q2入队，这样新元素就是q2的前端，也是栈顶元素。


![](https://pic.leetcode-cn.com/bd09a4682954f1047032693ed7d8990e6433d3ebbde216bc352dfabce2c7a34d.jpg)


push的时间复杂度为O(n)


![](https://pic.leetcode-cn.com/9c466cbd02ab57ef512cad22b218b210aa7f4e7601e685f6cd0457253cb3dd28.jpg)

pop的时间复杂度为O(1)

同学们不妨也自己实现一下。

**那有没有不是用两个队列的思路？我们可以看到，利用两个队列主要是为了改变队列的先进先出的特点。如果我们在一个队列里面进行push时，反转数据把栈顶元素翻转到队列前端，那是不是也是一样的效果呢？**

#### 方案代码

双队列，pop O(n)，push O(1):
```
from collections import deque

class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q1 = deque()
        self.q2 = deque()

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q1.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        while len(self.q1) > 1:
            self.q2.append(self.q1.popleft())
        tmp = self.q1.popleft()
        self.q2,self.q1 = self.q1, self.q2
        return tmp


    def top(self) -> int:
        """
        Get the top element.
        """
        while len(self.q1) != 1:
            self.q2.append(self.q1.popleft())
        tmp = self.q1.popleft()
        self.q2.append(tmp)
        self.q2,self.q1 = self.q1,self.q2
        return tmp

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """

        return not bool(self.q1)

```



单队列，pop O(1)，push O(n):
```
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q.append(x)
        q_length = len(self.q)
        while q_length > 1:
            self.q.append(self.q.pop(0)) 
            q_length -= 1

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.q.pop(0)

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.q[0]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not bool(self.q)
```
