### 解题思路
python解答：
要点1：借助list创建队列；
要点2：list.append()实现队尾插入；
要点3：list.pop(0)实现队头弹出；
要点4：遍历方法求得队列最大值。

### 代码

```python
class MaxQueue(object):

    def __init__(self):
        self.queue = []


    def max_value(self):
        """
        :rtype: int
        """
        size = len(self.queue)
        if size==0:
            return -1
        maxV = self.queue[0]
        for i in range(1, size):
            if self.queue[i] > maxV:
                maxV = self.queue[i]
        return maxV


    def push_back(self, value):
        """
        :type value: int
        :rtype: None
        """
        self.queue.append(value)


    def pop_front(self):
        """
        :rtype: int
        """
        if self.queue == []:
            return -1
        else:
            return self.queue.pop(0)



# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```