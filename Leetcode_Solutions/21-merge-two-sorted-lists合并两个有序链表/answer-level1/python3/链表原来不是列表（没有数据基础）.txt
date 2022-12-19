用列表的处理方式提交了两遍，系统报错才知道合并有序链表不等于合并列表；
写一个列表冒泡排序题解，希望不会挨揍；新人见谅；
class Solution:
    def mergeTwoLists(self,l1,l2):
        if l1 is None:
            return l2
        elif l2 is None:
            return l1
        else:
            l1 += l2
            n = len(l1)
            for i in range(n):
                for j in range(0,n-i-1):
                    if l1[j] > l1[j+1]:
                        l1[j],l1[j+1] = l1[j+1],l1[j]
            return l1

链表结果如下：
class Solution:
    def mergeTwoLists(self,l1,l2):
        if l1 is None:
            return l2
        elif l2 is None:
            return l1
        else:
            res = ListNode(None)
            node = res
            while l1 and l2:
                if l1.val < l2.val:
                    node.next,l1 = l1,l1.next
                else:
                    node.next,l2 = l2,l2.next
                node = node.next
            if l1:
                node.next = l1
            else:
                node.next = l2
            return res.next
        