参考：[https://leetcode-cn.com/problems/sort-list/solution/148-pai-xu-lian-biao-bottom-to-up-o1-kong-jian-by-/]()
```
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def creat(A):
    p = head = ListNode(A[0])
    for i in A[1:]:
        p.next = ListNode(i)
        p = p.next
    p.next = None
    return head


#A = [1, 15, 7, 9, 2, 5, 10]
A = [4, 2, 1, 3]
c_head = creat(A)


class Solution:
    def sortList(self, head):  # head：4->2->1->3
        L = 0
        p = head
        while p:
            L += 1
            p = p.next
        dummyHead = ListNode(0)
        dummyHead.next = head

        step = 0
        while step <= L:  # 步长—>2,4,8
            cur = dummyHead.next
            tail = dummyHead
            while cur:
                left = cur  # cur的左边，需要合并的前半部分 4,2
                right = self.cut(left, step)  # cut的右边, 出步长的链表：1,2
                cur = self.cut(right, step)  # 表示链表剩余的部分

                tail.next = self.merge(left, right)  # 合并排序两端链表,并插入到末尾结点之后
                while tail.next:
                    tail = tail.next  # 记录插入新结点之后的链表尾结点
            step = step * 2 + 1
        return dummyHead.next

    def cut(self, head, step):
        """从链表中截取步长为step的段"""
        p = head
        while p and step:
            p = p.next
            step -= 1

        if not p:
            return None

        next = p.next  # 返回截断的后半部分
        p.next = None  # 截断
        return next

    def merge(self, left, right):
        dummyHead = ListNode(0)  # 虚拟头
        p = dummyHead
        while left and right:
            if left.val < right.val:
                p.next = left
                p = left
                left = left.next
            else:
                p.next = right
                p = right
                right = right.next
        p.next = left if left else right
        return dummyHead.next  # 返回排序后的结果


S = Solution()
ans = S.sortList(c_head)
while ans:
    print(ans.val)
    ans = ans.next

```
