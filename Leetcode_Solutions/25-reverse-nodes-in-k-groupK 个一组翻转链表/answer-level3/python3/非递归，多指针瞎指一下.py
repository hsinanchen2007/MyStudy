# 这里的思路是最直观一看就想出来的思路，可是想出思路用了30s，写成代码用了30分钟都不止
![leetcode困难，链表内部翻转.jpg](https://pic.leetcode-cn.com/e04688c95af39edd6ffb060439f2e0cedeb9308fb139d9906db9b0745f9f089f-leetcode%E5%9B%B0%E9%9A%BE%EF%BC%8C%E9%93%BE%E8%A1%A8%E5%86%85%E9%83%A8%E7%BF%BB%E8%BD%AC.jpg)
图解写错了，k里面的k应该是n才对，表示节点的编号，k根据题意表示的是每k个节点翻转内部



```



class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        n = 1
        dummyhead = ListNode(3)
        dummyhead.next = head
        l = dummyhead
        while head != None:
            if n % k == 0:
                r = head.next
                h2 = headlast = l.next
                h3 = h2.next
                if h3 != None:
                    h4 = h3.next
                while h3 != r:
                    h3.next = h2
                    h2 = h3
                    h3 = h4
                    if h3 != None:
                        h4 = h4.next
                headlast.next = r
                l.next = h2
                l = headlast
                head = headlast
            head = head.next
            n += 1
        return dummyhead.next
```