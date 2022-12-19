**解题思路：**
1、定义快慢指针，若两指针相遇则表示有环，任意指针为空则表示无环，记录相遇点；
2、定义两个相同速度的指针，分别从头和相遇点出发，再次相遇的地方即为环入口；

## 示例代码

    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #考虑边界条件：
        if head == None or head.next == None or head.next.next == None:
            return None
        #定义快、慢两个指针，如果两个指针相遇表示有环
        a = head.next
        b = head.next.next
        while a != None and b != None:
            #如果两个指针相遇，跳出循环
            if a == b:
                break
            a = a.next
            b = b.next
            if b != None:
                b = b.next
        #如果a或b任意一个为空，则无环
        if a == None or b == None:
            return None
        b = head
        #a从头开始走，b从相遇点开始走，再次相遇的地方就是环的入口
        while a != b:
            a = a.next
            b = b.next
        return a