### 解题思路
此处撰写解题思路

### 代码

```python
class MyStack(object):

    def __init__(self):
        self.__list = []#用一个列表来存储数据


    def push(self, x):
        self.__list.append(x)#python自带方法


    def pop(self):
        return self.__list.pop()#python自带方法


    def top(self):
        arr = self.__list[-1:]#获得列表最后一个元素
        top_1 = arr[0]
        return top_1


    def empty(self):#实现列表是否为空
        return len(self.__list) == 0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```