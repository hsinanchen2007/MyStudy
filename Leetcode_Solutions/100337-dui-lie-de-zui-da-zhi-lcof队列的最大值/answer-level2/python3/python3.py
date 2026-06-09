### 解题思路

没什么好说的，熟练一下python3的list的api

max(arr) ==> 返回list里最大值
arr.append(val) ==> 在list尾部增加一个值
arr.pop(index) ==> 移除列表中的一个元素（默认最后一个元素），并且返回该元素的值

### 代码

```python3
class MaxQueue:

    def __init__(self):
        self.maxNum = 0
        self.arr = []


    def max_value(self) -> int:
        if len(self.arr) > 0 :
            return max(self.arr)
        else:
            return -1

    def push_back(self, value: int) -> None:
        self.arr.append(value);

    def pop_front(self) -> int:
        if len(self.arr) == 0:
            return -1
        else:
            return self.arr.pop(0)



# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```