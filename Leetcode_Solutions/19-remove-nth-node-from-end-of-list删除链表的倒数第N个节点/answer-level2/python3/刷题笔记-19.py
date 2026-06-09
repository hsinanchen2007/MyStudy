# 两次遍历
这里把待删除节点定义为**目标节点**。
1. 第一次遍历链表：获取链表的长度
2. 第二次遍历链表：找到**目标节点**的前一节点
3. 把**目标节点**前一节点的next指向**目标节点**的后一节点，就可以删除**目标节点**了

```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        prev = ListNode(0)
        prev.next = head
        
        # 第一次遍历：获取链表长度
        temp = head
        length = 0
        while temp:
            temp = temp.next
            length += 1
        
        # 第二次遍历：指针指向目标节点的前一节点
        node_index = length - n
        node = prev
        i = 0
        while i < node_index:
            node = node.next
            i += 1
        
        # 删除目标节点
        node.next = node.next.next
        return prev.next
```

# 一次遍历
这里把待删除节点定义为**目标节点**。
1. 初始化一个哑节点，下一结点指向链表的head
2. 初始化两个指针，指向哑节点
3. 移动其中一个指针，保证两个指针之间间隔**n**个节点，这里把它称为**快指针**，把另一个尚未移动的指针称为**慢指针**
4. 同步移动两个指针，直到**快指针**指向空节点，也即，指向链表的尾部
5. 此时，**慢指针**刚好指向**目标节点**的前一节点
6. 把**慢指针**指向节点的next指向**目标节点**的后一节点，就可以删除**目标节点**了

```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        first = dummy
        second = dummy
        for i in range(n+1):
            second = second.next
        
        while second:
            first = first.next
            second = second.next
            
        first.next = first.next.next
        return dummy.next
```


# notes
作为链表小白，一开始不知道怎么正确返回新链表的头结点，看了官方题解才知道可以借助哑节点。

修改的链表要和dummy指向的链表是同一个链表，而不是新指向一个链表再修改。

遍历链表时需要注意循环的起始条件，比如是从0开始还是1开始、从head开始还是从dummy开始，这些都会对指针的位置有影响。