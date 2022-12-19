### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    # 竟然不允许给ListNode添加新的方法，只好在class外添加方法了
    # def node2Number(self):
    #     result = self.next.node2Number() * 10 + self.val if self.next else self.val
    #     return result

    # def __str__(self):
    #     result = str(self.val) if self.next is None else str(self.val) + ' -> ' + self.next.__str__()
    #     return result

def node2Number(node):
    result = node2Number(node.next) * 10 + node.val if node.next else node.val
    return result

def number2Node(num):
    result = ListNode(num%10)
    val = (num - num%10)//10
    print(result.val,val)
    if val:
        result.next = number2Node(val)
    return result
# 1000000000000000000000000000001
# 465
# 1000000000000000000000000000466
# l1 = ListNode(2)
# print(l1.node2Number())
# print(l1)
# l1.next = ListNode(8)
# print(l1.node2Number())
# print(l1)
# print(number2Node(234))
# print(number2Node(1000000000000000000000000000466))
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # print(node2Number(l1))
        # print(node2Number(l2))
        result = node2Number(l1) + node2Number(l2)
        # print(result)
        return number2Node(result)
        
        # result = ListNode(0)
        # while (l1 is not None or l2 is not None):
        #     result.val = l1.val + l2.val if l1.val + l2.val < 10 else l1.val + l2.val - 10
        # result.x = l1.x + l2.x - 10 if l1.x + l2.x >= 10 else l1.x + l2.x
        # if isinstance(l1.next, ListNode) and isinstance(l2.next, ListNode):
        #     addTwoNumbers(self, l1.next, l2.next)
        # elif isinstance(l1.next, ListNode) and l2.next is None:
        #     l1.next.x = l1.next.x + l
```