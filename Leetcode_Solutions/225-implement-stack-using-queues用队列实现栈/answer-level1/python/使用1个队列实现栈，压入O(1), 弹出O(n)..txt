压入: 直接往队列中添加数据即可.
弹出：设此时队列的长度为n，弹出队列的前n-1个元素, 并将它们依次添加到队列尾部. 再弹出队列头部的元素.
获取栈顶元素: 思路与弹出基本相同，实现细节略有不同.
判断栈是否为空: 读取队列长度看其是否大于0. 
代码如下: 

```
class MyStack(object):

    def __init__(self):
        self.list1=[]

    def push(self, x):
        self.list1.append(x)

    def pop(self):
        lena=len(self.list1)
        for _ in range(lena-1):
            x=self.list1.pop(0)
            self.list1.append(x)
        x=self.list1.pop(0)
        return x

    def top(self):
        lena=len(self.list1)
        for _ in range(lena):
            x=self.list1.pop(0)
            self.list1.append(x)
        return x

    def empty(self):
        if len(self.list1)>0:
            return False
        else:
            return True

