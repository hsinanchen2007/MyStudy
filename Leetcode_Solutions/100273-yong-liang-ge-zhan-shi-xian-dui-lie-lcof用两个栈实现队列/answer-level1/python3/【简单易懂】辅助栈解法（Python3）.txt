## 暴力解法

我们使用两个栈，一个是主栈st1，另一个为辅助栈st2.

对于Python，以及JavaScript来说，没有内置的栈结构。我们使用数组来模拟即可（栈是一种受限的数组）。

- 对于入栈，我们使用append， 即往尾部插入一个元素。
- 对于出栈，我们使用pop(-1)，即删除尾部的元素。

我们的算法比较简单：


- 初始化st1和st2为空
- appendTail 只是往主栈插入元素
- deleteHead的时候，我们将st1的元素转移到st2。 这个时候st2和st1的顺序是相反的。
- 那么st2的栈顶元素就是我们要删除的元素。我们将其弹出即可
- 最后我们重新将st2的元素放回st1，那么st1就相当于删除了栈顶元素。

比如，我们依次插入1，2，3，4，5，然后删除队首元素（此时应该删除1），我们的st1和st2：

![](https://pic.leetcode-cn.com/0cdead2d15bfc59cf8b47d0b89deb1e766dfb1c13bc53bdc4f401bb82363a835.jpg)

转移之后的st1和st2：

![](https://pic.leetcode-cn.com/87b0e86325a31fbf01c84bf429f52d716ad76391e08b355efe71244e0573c6d8.jpg)

> 虚线表示不存在




```python
class CQueue:

    def __init__(self):
        self.st1 = []
        self.st2 = []
        

    def appendTail(self, value: int) -> None:
        self.st1.append(value)
        

    def deleteHead(self) -> int:
        while self.st1:
            cur = self.st1.pop(-1)
            self.st2.append(cur)
        res  = self.st2.pop(-1) if self.st2 else - 1
        # restore
        while self.st2:
            cur = self.st2.pop(-1)
            self.st1.append(cur)
        return res
```


## 优化

我们发现我们没有必要重建st1，原因在于既然st2已经是st1的反序了。那么重点来了，我们其实st2有数据，我们就弹出st2的栈顶元素即可。当st2没数据了，说明st1在st2转移的数据用完了，我们再将st1的元素全量转移到st2即可。


```python
class CQueue:

    def __init__(self):
        self.st1 = []
        self.st2 = []
        

    def appendTail(self, value: int) -> None:
        self.st1.append(value)
        

    def deleteHead(self) -> int:
        if not self.st2:
            while self.st1:
                cur = self.st1.pop(-1)
                self.st2.append(cur)
        return self.st2.pop(-1) if self.st2 else - 1
```




欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)