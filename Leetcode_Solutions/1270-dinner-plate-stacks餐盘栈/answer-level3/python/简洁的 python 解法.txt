### 解题思路
这个题目用 python 做很简单
python 中使用 list 实现栈
我们定义几个类的属性：
 1. self.s = [[]] ，一个list 的 list ，这里面是我们要操作的所有的栈
 2. self.cur_id = 0 代表下一个 push 操作对应的栈的 id
 3. self.capacity 就是每个栈的容量

操作：
 1. push：需要先判断 cur_id 指向的栈还有没有空间，如果没有，看看右边还有没有栈，有就 cur_id 加一，否则添加新栈
 2. pop：判断最右边的栈是否有元素，没有就销毁栈并左移
 3. popAtStack：判断指定栈是否存在和有元素

### 代码

```python
class DinnerPlates:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.s = [[]]
        self.cur_id = 0


    def push(self, val: int) -> None:
        while True:
            if len(self.s[self.cur_id]) < self.capacity: break
            self.cur_id += 1
            if len(self.s) == self.cur_id:
                self.s.append([])
        self.s[self.cur_id].append(val)


    def pop(self) -> int:
        i = len(self.s)-1
        while not self.s[i]:
            if i == 0: return -1
            self.s.pop()
            i -= 1
        self.cur_id = min(self.cur_id, i)
        return self.s[i].pop()


    def popAtStack(self, index: int) -> int:
        if index < len(self.s) and self.s[index]:
            self.cur_id = min(self.cur_id, index)
            return self.s[index].pop()
        return -1



# Your DinnerPlates object will be instantiated and called as such:
# obj = DinnerPlates(capacity)
# obj.push(val)
# param_2 = obj.pop()
# param_3 = obj.popAtStack(index)
```