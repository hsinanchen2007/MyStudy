1. 定义两个指针 fast 和 slow，二者初始化都指向在 head 位置
2. 其中，先让 fast指针遍历列表 n 个元素，即让 fast 和 slow 之间隔开 n 个元素
3. 在 fast 遍历完 n 个元素之后，slow 指针开始与 fast 指针同步遍历，直到 fast 指针指向链表末尾NULL
4. fast 指针指向链表末尾NULL之后，fast 与 slow 之间相隔n个元素，即让 slow 指针所指的元素的 next 指向下个元素的 next 即可完成删除。



class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        fast = head
        slow = head
        while(n > 0):
            fast = fast.next
            n -= 1
        if(fast == None):   
            # 若fast跑出列表之外，说明n刚好等于列表的长度
            # 即需要删除的元素为列表的头节点
            return head.next

        while(fast.next != None):
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next

        return head