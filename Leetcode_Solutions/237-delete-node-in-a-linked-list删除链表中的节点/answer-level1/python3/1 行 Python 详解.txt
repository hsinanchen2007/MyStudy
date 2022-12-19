## 题解
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val, node.next = node.next.val, node.next.next
```
- 将当前节点的值和指针都修改为下一个节点的值和指针即可，相当于让当前节点冒充下一个节点，那么远离啊的当前节点被修改消除，原来节点的下一位节点因为没有被指针连接而失去意义
- 此题考查python函数的传参形式为“传对象引用”，相当于浅拷贝（对于可变对象来说）

## 细节补充
- `node = node.next`是不行的，因为这里只是改了函数参数引用的对象，而原来传进来的 node 没有任何改变
- 详细说明：如果Python的函数得到的参数是可变对象（比如list，set，这样的，内部属性可以改变的），那么我们实际得到的是这个对象的浅拷贝。比如这个函数刚刚开始的时候题目传进来一个参数node，我们设这个节点为A，那么实际上得到的参数node是一个对于A的一个浅拷贝，你可以想象node是一把钥匙，它可以打开真正的节点A的门，如果我们现在让`node = node.next`，那么我们只是换了钥匙，变成了打开 A.next 的门的对应的钥匙，因此链表没有被修改， A没有被修改，只是我们手里的钥匙变了。而如果我们直接写`node.val, node.next = node.next.val, node.next.next`，就相当于我们先用钥匙找到 A 的门，然后修改了 A 的属性，链表发生变化

