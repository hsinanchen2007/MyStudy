执行用时 :44 ms, 在所有Python3提交中击败了95.78% 的用户
内存消耗 :13 MB, 在所有Python3提交中击败了95.45%的用户
```
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        count = 0
        dummy = ListNode(0)
        p1 = dummy
        p2 = None
        flag = True
        while head is not None:
            count += 1
            node = ListNode(head.val)
            if m<=count<=n:
                # 再m-n之间的部分头插入
                node.next = p1.next
                p1.next = node
                head = head.next
                if flag:
                    # 保存一个指针指向第m个结点
                    p2 = node
                    flag = False
            elif count<m:
                # 小于m的部分尾插入
                p1.next = node
                p1 = p1.next
                head = head.next
            else:
                # 大于m的部分直接尾插
                p2.next = head
                return dummy.next
        # 处理链表长度=m的情况
        return dummy.next
"""
另一个思路，直接在原始链表进行反转
定位到m的前一个元素，用prev指向，第m个元素,cur指向
"""
```
