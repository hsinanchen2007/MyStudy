##遍历解法：
遍历解法比较简单，遍历每一个节点时，将当前节点的 next 指向上一节点即可，在完成这一步的时候还要记录当前节点的下一节点，以便继续遍历。要注意第一个节点的 next 需要指向 None。
```py
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        # 记录当前所在的节点
        cur = head
        # 记录当前节点的前一个节点，这里设为 None 是为了让第一个节点的 next 最终指向None
        pre = None
        while cur != None:
            #记录当前节点的下一个节点，以便之后能够继续遍历
            nex = cur.next
            cur.next = pre
            pre = cur
            cur = nex
        return pre```

##递归法
写递归解法，我的习惯是先写一个 if.. 语句，确认其终止条件，然后写递归相关的代码。
递归的主体和循环代码部分的思路相同，是使当前 head 节点的下一个节点的 next 指向head。还算是比较简单。
```py
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        #如果 head 和 head.next 其有又一个不存在，即单向链上没有元素或者只剩一个元素，那么就终止递归
        if not head or not head.next:
            return head
        
        #如果 head 和 head.next 存在，就继续递归
        #resultFromNextRecursion是始终原来链上最末端的元素
        resultFromNextRecursion = self.reverseList(head.next)
        #进行 next 的指向调转
        head.next.next = head
        head.next = None
        return resultFromNextRecursion
```

第二天打卡，若有任何错误，还请指正。