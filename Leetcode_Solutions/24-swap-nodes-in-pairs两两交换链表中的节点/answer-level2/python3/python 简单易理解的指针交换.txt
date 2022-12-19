### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        """
        思路： 设置虚拟头结点和四个指针
        """
        dummyHead = ListNode(0)
        dummyHead.next = head # 设置一个虚拟头结点
        
        p = dummyHead # 指向虚拟头结点的指针
        while p.next and p.next.next: # p节点后面还存在两个节点才能交换pair
            node1 = p.next # 第一个节点
            node2 = node1.next # 第二个节点
            nnext= node2.next # 第三个节点
            # 交换操作： p => node1 => node2 => nnext 变为： p=>node2 =>node1 => nnext
            node2.next = node1 # 把node2.next重新指向node1
            node1.next = nnext # 把node1.next指向nnext
            p.next = node2 # 把p.next 指向 node2
            p = node1 # 然后p移动到node1,相当于node1是新的虚拟头结点
        return dummyHead.next # 最后返回头结点
```