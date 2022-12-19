#### 算法思路
1. 定义一个数组作为队列，初始化`size`
2. 当调用`next(val)`时，向数组中添加`val`值
3. 每次维护队列的长度为`size`大小，若超过则弹出队首元素
#### 参考代码
```
class MovingAverage:

    def __init__(self, size: int):
        """
        Initialize your data structure here.
        """
        self.queue = []
        self.size = size

    def next(self, val: int) -> float:
        self.queue.append(val)
        if len(self.queue) > self.size:
            self.queue.remove(self.queue[0])
        return sum(self.queue)/len(self.queue)
```
#### 复杂度分析
- 时间复杂度：*O（N）*，*N*为数组的长度。
- 空间复杂度：*O（N）*，使用了数组。

![白色背景关注.jpg](https://pic.leetcode-cn.com/47d1b5430e869ed420bb0c6e8a90250773528ccf1bf6d4d43aef80dd326eeef9-%E7%99%BD%E8%89%B2%E8%83%8C%E6%99%AF%E5%85%B3%E6%B3%A8.jpg)
