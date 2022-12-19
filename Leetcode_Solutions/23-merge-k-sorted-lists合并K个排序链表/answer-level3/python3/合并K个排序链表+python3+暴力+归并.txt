####  方法1：依次合并两个有序链表（暴力）

| 时间复杂度 | 空间复杂度 |
| :--------: | :--------: |
|   见备注   |    O(l)    |

*备注：假设合并的两个链表的长度为n1和n2，则一次合并操作的时间复杂度为O(n1+n2)。则假设所有链表的长度为[n1, n2, n3, n4, n5 ......]，则时间复杂度为：(n1+n2)+(n1+n2+n3)+(n1+n2+n3+n4) ......。*

**基本思路：**

> 遍历链表数组，依次合并两个有序链表。

**代码：**

```python []
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        def mergeTwoList(l1, l2):  # 合并两个有序链表
            pre = ListNode(None)
            head = pre

            while l1 and l2:
                if l1.val <= l2.val:
                    pre.next = l1
                    l1 = l1.next
                    pre = pre.next
                else:
                    pre.next = l2
                    l2 = l2.next
                    pre = pre.next
            pre.next = l1 if l1 else l2
            return head.next

        if not lists:
            return
        r = lists[0]
        for i in range(1, len(lists)):
            r = mergeTwoList(r, lists[i])

        return r
```

####  方法2：通过归并法依次两两合并

| 时间复杂度 | 空间复杂度 |
| :--------: | :--------: |
| O(n*logk)  |    O(l)    |

*备注：使用归并法，一次完整的归并过程时间复杂度为O(n)，其中n为所有链表长度之和，归并深度为logk，k为链表个数。*

**基本思路：** 使用归并思想，两两合并链表。

> 

**代码：**

```python []
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        def mergeTwoList(l1, l2):  # 合并两个有序链表
            pre = ListNode(None)
            head = pre

            while l1 and l2:
                if l1.val <= l2.val:
                    pre.next = l1
                    l1 = l1.next
                    pre = pre.next
                else:
                    pre.next = l2
                    l2 = l2.next
                    pre = pre.next
            pre.next = l1 if l1 else l2
            return head.next

        if not lists:
            return
        s = 1  # 归并步长，代表当前合并的两个链表的索引差
        n = len(lists)
        while s < n:
            for i in range(0, n, 2 * s):  # 循环步长为归并步长的两倍
                if i + s <= n - 1:
                    lists[i] = mergeTwoList(lists[i], lists[i + s])
            s *= 2
        return lists[0]
```