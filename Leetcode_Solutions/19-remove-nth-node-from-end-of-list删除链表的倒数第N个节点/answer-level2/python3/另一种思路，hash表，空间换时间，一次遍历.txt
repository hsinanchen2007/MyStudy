题解中的双指针确实精妙

我做这个题，一开始就是另一种思路：哈希表。思路来源于之前看到的一个思想，hash表查找时间为O(1),比列表链表查找要快，常用于空间换速度。
要一次遍历就能删除任意位置的节点，一个办法就是先遍历一次链表，并把每个节点的位置和节点指针加入hash表，记总节点数为count
然后删除倒数第n个节点节点：
倒数第n个节点的位置：count - n + 1
倒数第n+1个节点的位置：count - n
让n+1节点的next = n节点的next，就把倒数n节点删除了

处理一下边界就是倒数n是首节点时，需要把head=首节点的next


```
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        node_dict = {}
        count = 0
        p = head
        while p:
            count += 1
            node_dict[count] = p
            p = p.next
            
        if n == count:
            head = node_dict[1].next
        else:
            node_dict[count-n].next = node_dict[count-n+1].next
        
        return head
```
