借鉴160相交链表双指针所采用的交叉遍历的办法进行数字的对齐。
代码还是非常简单的。

```
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        node1, node2, flag1, flag2 = l1, l2, 0, 0
        sumhead = ListNode(0)
        node = sumhead

        # 每个链表第一次遍历的时候当做0相加，第二次遍历的时候求和（不考虑进位）
        # 交叉遍历到了第二次的时候数字已经对齐了。
        # 想不出来如何一次往后遍历可以把进位搞定，所以先不考虑进位。
        while node1 and node2:
            node.next = ListNode(node1.val * flag1 + node2.val * flag2)
            node = node.next
            if not node1.next and not flag1: flag1, node1 = 1, l2
            else: node1 = node1.next 
            if not node2.next and not flag2: flag2, node2 = 1, l1
            else: node2 = node2.next
        
        # 把得到结果中的进位处理掉。
        flag = 1
        while flag:            
            pre, node, flag = sumhead, sumhead.next, 0
            while node:
                if node.val >= 10: 
                    node.val -= 10
                    pre.val += 1
                    flag = 1
                node, pre = node.next, pre.next
        # 再把前面的0去掉，注意结果为0的情况。
        while not sumhead.val and sumhead.next: sumhead = sumhead.next
        return sumhead
```
