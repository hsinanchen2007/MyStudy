这个道题非常好，可以通过此题学习多种解题思维
1.  利用栈
2.  尾插法，学习链表的删除与插入
3.  递归，学习链表的原地反转，递归的调用


```栈 []
class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        dumy = ListNode(-1)
        pre = dumy
        while True:
            count = k
            cur = head
            stack = []
            while count and cur:
                stack.append(cur)
                cur = cur.next
                count -= 1
            if count:
                pre.next = head
                break

            while stack:
                pre.next = stack.pop()
                pre = pre.next

            pre.next = cur
            head = cur
        return dumy.next
```
```尾插法 []
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        # 创建头部节点并与head连接
        dumy = ListNode(-1)
        dumy.next = head

        # 创建指向反转段链表的起始节点前驱与末尾的指针
        pre = dumy
        tail = dumy
        while True:
            count = k
            while count and tail:
                count -= 1
                tail = tail.next
            # tail 为空，则不足三个
            if not tail:
                break

            # 记录要反转的第一个节点记head，反转后其为下一段的前驱节点
            head = pre.next

            # 将这段链表的节点依次插入tail之后
            while pre.next != tail:
                # 将temp节点截取下来：
                temp = pre.next
                pre.next = temp.next

                # 将temp节点插入尾部节点之后
                temp.next = tail.next
                tail.next = temp

            # 此处的head是记录的下一段需要反转的前驱节点
            pre = head
            tail = head
        return dumy.next
```
```递归 []
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        # 记录
        cur = head
        count = 0
        while count !=k and cur:
            cur = cur.next
            count +=1
        if count==k:
            # res 为反转后链表的首节点
            res = self.reverseKGroup(cur,k)
            # 反转
            while count:
                # 存储当前反转段落的首节点的下一节点
                temp = head.next
                # 将首节点next指向返回的res
                head.next = res
                
                res = head
                head = temp
                count -=1
            
            # res 为反转之后的首节点 将其赋值给head以便return返回
            head = res
            
        return head
```



