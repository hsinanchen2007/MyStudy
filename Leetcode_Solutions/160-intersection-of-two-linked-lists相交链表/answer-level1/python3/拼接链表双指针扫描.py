      两个链表长度不一定相等，但是拼接在一起以后一定等长。pA和pB开始分别指向hA和hB，然后分别遍历两个链表。
假设链表hA比hB长，则当pB指向None时，pA仍指向链表hA的某个结点。接下来pA继续后移一位，pB指向hA。
二者继续后移，则当pA指向None时，pB仍指向链表hA的某个结点。接下来pB继续后移一位，pA指向hB，此时pA和pB对齐了。
之后二者继续后移，当pA==pB时，说明二者指向了同一结点（也可能同时指向了None），循环结束。
![集锦.png](https://pic.leetcode-cn.com/24d15836cbf3ea2ad5848b8bc748cb4cba71e70f71a6296c3f5add36d9955729-%E9%9B%86%E9%94%A6.png)
```
def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        pA, pB = headA, headB
        while pA != pB:
            pA = pA.next if pA else headB
            pB = pB.next if pB else headA
        return pA
```
也可以分步骤写成这样：
```
def getIntersectionNode4(self, headA: ListNode, headB: ListNode) -> ListNode:
        pA, pB = headA, headB
        for i in range(2):#pA和pB各指向None一次，然后二者刚好对齐
            while pA and pB:
                pA, pB = pA.next, pB.next
            if pA is None:
                pA = headB
            else:
                pB = headA
        while pA != pB: #遍历可能存在共同结点的区域
            pA, pB = pA.next, pB.next
        return pA
```



