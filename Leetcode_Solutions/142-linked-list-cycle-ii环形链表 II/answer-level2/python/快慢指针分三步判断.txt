思路：三个步骤
    1. 判断是否有环：快慢指针，fast每次向前走两步，slow每次向前走一步。使用hasCyc标记位标志链表是否有环。
    2. 判断环的长度：若hasCyc = True，则fast和slow两个指针会指在环中的某一个位置。记录当前位置，依旧使用快慢指针判断环的长度。
    3. 判断环的入口：计算出环的长度count后，指针front先走count步，之后behind开始向前移动，前后两个指针均一次向前走一步，直到两个指针相遇，即为环的入口。
```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head:
            return None
        fast, slow = head, head
        
        # 判断是否有环
        hasCyc = False
        while fast:
            if fast.next == None:
                break
            else:
                fast = fast.next.next
                slow = slow.next
            if fast == slow:
                hasCyc = True
                break
                
        # 若存在环，上一次循环后fast和slow两个指针会指在环中的某一个位置
        # 计算环的长度
        if hasCyc == False:
            return None
        else:
            # 存储相遇的位置
            tmp = slow
            count = 1
            slow = slow.next
            while slow != tmp:
                count += 1
                slow = slow.next
   
        # 得到环的长度为count
        # 慢指针先走count步
        front, behind = head, head
        for _ in range(count):
            front = front.next
        # 前后指针一起走，直到相遇，为环的入口pos

        idx = 0
        while front.val != behind.val:

            idx += 1
            front = front.next
            behind = behind.next
            
           
        return front
```