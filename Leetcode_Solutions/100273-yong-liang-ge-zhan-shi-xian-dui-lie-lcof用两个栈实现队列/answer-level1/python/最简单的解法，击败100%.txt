一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 解题思路
一个栈用来存储 pop时弹出stack2，stack2为空，pop出stack1存储在stack2中

### 代码

```python
class CQueue(object):

    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def appendTail(self, value):
        self.stack1.append(value)
    
    def deleteHead(self):
        if not self.stack2:
            while self.stack1:
                self.stack2.append(self.stack1.pop(-1))
        if len(self.stack2) == 0: 
            return -1
        return self.stack2.pop(-1)
```