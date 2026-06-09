dummy指针的设置比较重要。

另外，在链表的题目里边，判断是否为空指针非常关键，而且需要格外小心。

具体实现的细节代码注释的很清晰。
```
class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        # 首先需要设置一个dummy节点，指向head节点。
        # 然后设置一个slow、fast和p节点
        # slow节点指向的是第一个下一节点大于x的节点。 因为我们看到，大于或等于x的值的顺序是不变的；
        # 而p则指向的是第一个大于x的节点，也就是slow的下一个节点
        # 最后fast节点指向比x小的节点，然后不停的插入到slow节点和p节点中间
        
        if not head:
            return head
        
        dummy = slow = fast = p = ListNode(0)
        dummy.next = head

        while slow.next and slow.next.val < x:
            slow = slow.next
            p = p.next
            fast = fast.next
        if not slow.next: # 这个时候说明所有的数字都比x小，也就不需要调整了
            return head
        p = slow.next 
        fast = p # 此时已经确定了p和slow的值，然后将fast从p处开始往后遍历
        while fast.next:
            while fast.next and fast.next.val >= x: 
                fast = fast.next
            
            if not fast.next: # 说明已经遍历结束了
                break
            
            slow.next = fast.next # 将slow后面小于x的值放置到slow和p中间
            fast.next = fast.next.next
            slow.next.next = p
            slow = slow.next # 这个时候需要将slow的位置往后移动一个，而p的位置始终不变
        
        return dummy.next
        
```
