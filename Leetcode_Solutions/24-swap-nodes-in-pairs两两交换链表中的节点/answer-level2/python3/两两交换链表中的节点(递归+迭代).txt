### 方法一: 递归

### 代码

```python
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:

        if not head or not head.next:
            return head

        first_node = head
        second_node = head.next
        
        first_node.next = self.swapPairs(second_node.next)
        second_node.next = first_node

        return second_node
```
### 方法二: 迭代

```python
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:

        dummy = ListNode(0)
        dummy.next = head
        pre = dummy

        while pre.next and pre.next.next: # 至少有两个元素才进行交换
            first = pre.next # 交换的第一个节点是 pre 的下一个节点
            second = pre.next.next # 交换的第二个节点是 pre 的后的第二个节点
            pre.next = second # 此时将 pre 指向 第二个节点
            first.next = second.next # 将 first node 指向 下一次交换的第一个节点 
            second.next = first # second 指向 first 实现交换
            pre = first # 此时的 first 扔是第一个 节点, 而 first.next 是 第三个节点.
                        # 那么这样就实现了循环, pre 又指向了剩下的节点里的第一个节点
        return dummy.next
```    









```