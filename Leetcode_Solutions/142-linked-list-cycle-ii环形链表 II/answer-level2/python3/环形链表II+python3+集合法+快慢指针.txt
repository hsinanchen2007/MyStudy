####  方法1：将遍历过的节点存储起来

| 时间复杂度 | 空间复杂度 |
| :--------: | :--------: |
|    O(n)    |    O(n)    |

*备注：遍历时间复杂度为O(n)，判断节点在不在集合内的复杂度为O(l)，综合时间复杂度为O(n)*

**基本思路：**

> 用一个集合将遍历过的节点存储起来，判断当前节点是否曾遍历过。

**代码：**

```python []
class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        res = set()
        while head:
            if head in res:
                return head
            res.add(head)
            head = head.next
        return
```

####  方法2：快慢指针

| 时间复杂度 | 空间复杂度 |
| :--------: | :--------: |
|    O(n)    |    O(l)    |

**基本思路：**

> 如代码注释

**代码：**

```python []
class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if not head:
            return

        # 快慢指针，快指针速度是慢指针的两倍
        # 1. 环前的长度为n，假设环长度大于环前的长度；
        # 2. 慢指针走n步，到达环口，快指针走了2n步；
        # 3. 相遇1：慢指针走过n+m, 快指针走过2n+2m，环的长度相当于n+m（n+2m-m），两个指针都位于距环口m处；
        # 4. 重新定义两个指针，指针1指向头节点，指针2指向相遇点，以相同的速度遍历；
        # 5. 相遇2：指针1走n步，指针2走n步，刚好位于入口。

        slow, fast = head, head

        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                while True:
                    if slow == head:
                        return slow
                    head = head.next
                    slow = slow.next
        return
```