## 问题如下, 在注释里
```
class Solution2(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
         # 递归
        pre = None
        curr = head
        return self.helper(pre, curr)
    def helper(self, pre, curr):
        if curr.next == None:  # base：如果下一个节点为空，则到最后了，直接把最后一个节点指向前一个，然后返回最后一个节点
            curr.next = pre
            print(curr)  # ????这里可以打印出值为什么返回的是空？???
            return curr
        else:  # 不是最后一个节点
            tem = curr.next  # 保存下来下一个节点
            curr.next = pre  # 翻转
            pre = curr       # 把前一个指针指向当前
            curr = tem       # 把当前节点往后移动
        self.helper(pre, curr)
s = Solution2()
l1 = ListNode(1)
l2 = ListNode(2)
l3 = ListNode(3)
l4 = ListNode(4)
l5 = ListNode(5)
l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l5
print(s.reverseList(l1))
```