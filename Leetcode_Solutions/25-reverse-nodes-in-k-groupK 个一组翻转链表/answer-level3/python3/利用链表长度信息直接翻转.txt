## 思路
由于本题要求`K个一组翻转链表`，如果不足K个就保持原来顺序不变。那么有一个必需的操作：判断剩下的链表节点数目是否满足翻转的要求。
因此，第一反应便是直接求得链表的长度，直接用**整除**操作便可以得到一共需要翻转多少组，那么剩下的节点直接串联到翻转过后的链表尾部即可。
## 实现
1. 为了便于操作，为原链表添加一个头节点，新建一个链表的头节点。  
2. 直接迭代$\lfloor\frac{L}{k}\rfloor$次：  
从原链表取出一个节点，插入到新建链表的插入位置。重复该操作k次，将新建链表的插入位置更新到新的尾部。
3. 将剩余的节点添加到新建链表的尾部。
## 代码
```Python
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        dummy_N, dummy_O = ListNode(0), ListNode(0)
        dummy_O.next = head
        length, node = 0, head
        while node:
            length += 1
            node = node.next
        node_N = dummy_N
        for _ in range(length//k):
            tail = dummy_O.next
            for _ in range(k):
                node_O = dummy_O.next
                dummy_O.next = node_O.next
                node_O.next = node_N.next
                node_N.next = node_O
            node_N = tail
        node_N.next = dummy_O.next
        return dummy_N.next
```