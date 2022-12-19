# 双队列

## 思路

本题和[232. 用栈实现队列](https://github.com/azl397985856/leetcode/edit/master/problems/232.implement-queue-using-stacks.md) 思想稍有不同。 相同之处在于都可以采用双xx来解决。而这道题稍微难一点。

需要明确一点的是，本题我使用python的数组来模拟队列。Python 中 pop(0) 表示从数组头删除一个元素， append(x) 表示向数组尾部添加一个元素。 `也就是说除了这两个API，我们不可以用别的数组api，当然也不可以直接用索引来操作，这都是不允许的。`

- 我们初始化两个队列q1和q2。其中q1是主队列，q2是辅助队列。
- push往q1末尾添加元素
- pop的时候，q1往q2转移，直到q1只剩下最后一个元素。我们将其返回即可。最后我们调换q1和q2
- top的时候我们复用pop，这样我们的q1实际上会少一个元素，我们再将其append回去即可。
- empty只需要判断q1是否为空即可

## 代码

```python
class MyStack:

    def __init__(self):
        self.q1 = []
        self.q2 = []


    def push(self, x: int) -> None:
        self.q1.append(x)


    def pop(self) -> int:
        while len(self.q1) > 1:
            self.q2.append(self.q1.pop(0))
        self.q1, self.q2 = self.q2, self.q1
        return self.q2.pop(0)


    def top(self) -> int:
        ans = self.pop()
        self.q1.append(ans)
        return ans
        


    def empty(self) -> bool:
        return len(self.q1) == 0
```


**复杂度分析**
- 时间复杂度：ppo 和 top 为 $O(N)$， push, empty 为 $O(1)$
- 空间复杂度：$O(N)$


# 一个队列

## 思路

实际上q2可以不存在，我们假想一个q2队列，将q1队列本身看成q2。 这样我们只需要将上面的pop方法稍加改造即可，其他代码不需要变化，具体见下方代码区。

## 代码

```python
class MyStack:

    def __init__(self):
        self.q1 = []


    def push(self, x: int) -> None:
        self.q1.append(x)


    def pop(self) -> int:
        n = len(self.q1)
        for _ in range(n - 1):
            self.q1.append(self.q1.pop(0))
        return self.q1.pop(0)


    def top(self) -> int:
        ans = self.pop()
        self.q1.append(ans)
        return ans
        


    def empty(self) -> bool:
        return len(self.q1) == 0
```

**复杂度分析**
- 时间复杂度：ppo 和 top 为 $O(N)$， push, empty 为 $O(1)$
- 空间复杂度：$O(1)$

# 延伸阅读

实际上现实中也有使用两个栈来实现队列的情况，那么为什么我们要用两个stack来实现一个queue？

其实使用两个栈来替代一个队列的实现是为了在多进程中分开对同一个队列对读写操作。一个栈是用来读的，另一个是用来写的。当且仅当读栈满时或者写栈为空时，读写操作才会发生冲突。

当只有一个线程对栈进行读写操作的时候，总有一个栈是空的。在多线程应用中，如果我们只有一个队列，为了线程安全，我们在读或者写队列的时候都需要锁住整个队列。而在两个栈的实现中，只要写入栈不为空，那么`push`操作的锁就不会影响到`pop`。

- [reference](https://leetcode.com/problems/implement-queue-using-stacks/discuss/64284/Do-you-know-when-we-should-use-two-stacks-to-implement-a-queue)

- [further reading](https://stackoverflow.com/questions/2050120/why-use-two-stacks-to-make-a-queue/2050402#2050402)

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
