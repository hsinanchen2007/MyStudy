### 解题思路
（1）队列queue正常入队和出队；队列max_queue保存递减元素，出队列中最大值时，从max_queue中弹出首个元素max_queue[0]
（2）关键在于如何 a）入队和 b）出队 才能保证max_queue是递减队列
（3）a) 入队时，queue正常入队，max_queue需要判断当前value 与max_queue队尾元素max_queue[-1]的大小，如果value 大于max_queue[-1]，则依次将max_queue的队尾元素弹出，然后添加value 
（4）b) 出队时，queue正常出队，max_queue需要判断，出队的元素是否是最大值，如果queue[0]==max_queue[0],则max_queue 也需要出队

### 代码

```python
class MaxQueue:

    def __init__(self):
        self.queue=[]
        self.max_queue=[]
        
    def max_value(self) -> int:
        if not self.queue:
            return -1
        print(self.max_queue)
        return self.max_queue[0]
        

    def push_back(self, value: int) -> None:
        self.queue.append(value)
        while self.max_queue and value > self.max_queue[-1]:
                self.max_queue.pop(-1)
        self.max_queue.append(value)

    def pop_front(self) -> int:
        if not self.queue:
            return -1
        if self.queue[0]==self.max_queue[0]:
            self.max_queue.pop(0)
        return self.queue.pop(0)


# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```