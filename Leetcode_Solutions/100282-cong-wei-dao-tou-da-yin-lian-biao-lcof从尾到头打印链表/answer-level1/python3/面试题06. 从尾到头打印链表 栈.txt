```
class Solution(object):
    def reversePrint(self, head):
        """
        :type head: ListNode
        :rtype: List[int]
        """
        stack= []
        
        while  head:
            stack.append(head.val)
            head = head.next

        return stack[::-1]
```

其实可以逆转链表，但是面试时要咨询面试官是否可以修改原数据结构，一般是不
使用 ::-1 来逆序输出
其实列表可以通过list.pop() 出栈