### 解题思路
此处撰写解题思路
使用单链表构造栈数据结构
将每个栈元素表示为一个节点（包含本元素值_elem及下一元素的指向_next），入栈操作即实例化新节点，并将头指针从上一元素指向新元素；
构造栈节点：
```
class stackNode():
    def __init__(self, elem, next=None):
        self.elem = elem
        self.next = next
```

初始化，即创造头指针:
```
self.head = None
```
入栈操作，即转移头指针指向:
```
self.head = stackNode(elm, self.head)
```
取栈顶数据，即取头数据:
```
return self.head.elem
```
出栈操作，即判断栈是否为空，若不为空则返回头节点数据，并滑动头指针:
```
elm = self.head
self.head = elm.next
return elm.elem
```
判栈空即返回头指针是否指向空；


