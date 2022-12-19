### 解题思路
## 思路一：三指针法
需要存储pre、cur、next三个位置上的节点，当断开cur和next的链时，链接cur和pre。
完成之后，向前移动一位，重复进行，直到尾节点。

注：考虑特殊情况：
1. 空链表
2. 只有一个节点的链表

```
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        
        if not head or not head.next:
            return head
        
        pre = None
        cur = head
        nex = head.next

        while nex != None:
            cur.next = pre

            pre = cur
            cur = nex
            nex = nex.next
        
        cur.next = pre
        
        return cur
```

时间复杂度：O(N)
空间复杂度：O(1)


## 思路二：递归!!
这个思路比较难理解！！！

### 1. 递归过程：
停止条件：当前节点的next是尾节点，即head.next == None,此时函数调用返回尾节点，也即反转后的头节点。

### 2. 回溯过程：
停止递归时，head指向倒数第二个节点，需要让此节点的下个节点重新指向此节点，同时断开此节点到下个节点的单向链。完成之后，返回尾节点。
重复上述过程，直到到达最后一个函数调用，即此时的head是头节点。添加新链，断开旧链。至此反转完成，返回cur，即尾节点。

在回溯过程中，始终返回尾节点；每一次回溯，就会更改一个节点的链接方向。


注：考虑特殊情况：
1. 空链表。因此需要判断head是否为空
2. 只有一个节点的链表。同样满足多节点的code

```
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        
        # stop recursion at last node and trackback
        if not head or not head.next:
            return head

        cur = self.reverseList(head.next)

        head.next.next = head
        head.next = None

        # always return last node and reverse during trackback
        return cur
```

时间复杂度：O(N)
空间复杂度：O(1)

