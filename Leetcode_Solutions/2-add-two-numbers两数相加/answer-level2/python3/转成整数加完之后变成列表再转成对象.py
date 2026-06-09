### 解题思路
请参考代码即可
1. 先转成整数
2. 整数相加，这样可以避免进位计算
3. 计算完毕后，转成列表
4. 使用列表生成对象链表
5. 然后返回根链表对象

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        i1: int = 0
        times: int = 0
        i2: int = 0

        while l1 is not None:
            i1 += pow(10, times)*l1.val
            times += 1
            l1 = l1.next

        times = 0

        while l2 is not None:
            i2 += pow(10, times) * l2.val
            times += 1
            l2 = l2.next

        it: int = i1 + i2
        ls: [] = list(str(it))
        ls.reverse()
        c: int = len(ls)

        void_node: ListNode = ListNode(-1)
        root_node: ListNode = void_node

        for idx in range(c):
            temp_node: ListNode = ListNode(ls[idx])
            root_node.next = temp_node
            root_node = root_node.next

        return void_node.next
```