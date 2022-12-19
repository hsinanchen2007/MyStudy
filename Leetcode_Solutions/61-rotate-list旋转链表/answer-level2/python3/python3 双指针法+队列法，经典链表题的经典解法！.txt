链表题目做来做去无非就这两种套路，指针（单指针，双指针）和列表（表示队列，表示栈）。下面就分开介绍：
### 方法一：用列表模拟队列
思路很简单直观，用列表将链表元素记下，将列表后面k个元素切下，拼到头部，再用此列表生成新链表即可。
也可以换个角度，将列表前面`length-k`个元素切下，拼到列表后面，再用此列表生成新链表即可。
```
class ListNode:
    def __init__(self, x, y):
        self.val = x
        self.next = y

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        visited = []
        while head: ## 记下链表全部的Node           
            visited.append(head)
            head = head.next
        length = len(visited)
        k = length - k%length if length else 0
        for _ in range(k):
            visited.append(visited.pop(0)) ## 前面切下拼到后面
        rst = None
        while visited: ## 生成新链表
            rst = ListNode(visited.pop().val,rst)
        return rst
```
时间O(n)，空间O(n)。
### 方法二：快慢双指针
快指针从第k个元素开始遍历，慢指针从头遍历，二者均为一次一个next。
快指针到链表尾时结束，此时将尾再指向头，形成环
然后慢指针的next就是我们要的结果链表。但是记得要将慢指针的next置为None来切断环。
```
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        try:
            k %= head.__str__().count('}') ## 偷懒计算链表长度并取余
        except:
            return
        fast=slow = head
        for _ in range(k): ## 快指针从第k个位置开始
            fast = fast.next       
        while fast and fast.next: ## 快慢指针同步，到快指针next为None时结束
            slow,fast = slow.next, fast.next
        fast.next = head ## 快指针尾指向头，形成环
        rst,slow.next = slow.next,None  ## 得到旋转后链表头，并将环切断形成尾
        return rst
```
时间O(n)，空间O(1)。

**重要的事情再说一遍：链表类题目无非指针+列表两种套路^_^**
