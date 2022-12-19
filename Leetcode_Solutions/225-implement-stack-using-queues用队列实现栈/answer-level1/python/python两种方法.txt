这题我看很多人说python没有队列，python不是有个自带的包Queue吗？我这里两个方法，一个是用两个队列，一个是用单列表。

**方法一：**
用两个队列，每次有新加入的元素时，a队列接收新元素后会把b队列里的元素一个个相加入自己，直到b队列空。此时将a和b交换，这样b队列执行get()方法得到的效果就是先进后出。不过因为python里Queue模块queue对象没有top()这种类似方法，所以我这里是先取出元素，这样就知道顶部元素了，然后再加入，可能因为这个原因，这种方法总是报超时。下面是代码：
```
from Queue import Queue


class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.a = Queue()
        self.b = Queue()
        self.first = None

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        #这里加这个判断是为了防止下面pop方法里添加first元素时first是None
        if type(x) is not int:
            return
        self.a.put(x)
        while not self.b.empty():
            self.a.put(self.b.get())

        self.a, self.b = self.b, self.a
        self.first = x

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        now = self.b.get()
        #先取出第一个元素才知道第一个元素的值，然后再加入队列
        self.first = self.b.get()
        self.push(self.first)
        return now

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.first

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return self.b.empty()


```

**方法二：**
这个就没什么好讲的了，是用的python里的list，基本上用的都是list的方法实现的，不过速度挺快的，超过了90%。
当然类似的还有python里的双端队列deque，也是基本上都是使用的自带的方法。

```
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.a = []

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.a.append(x)

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        return self.a.pop()

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.a[-1]

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        if self.a:
            return False
        
        return True
```
