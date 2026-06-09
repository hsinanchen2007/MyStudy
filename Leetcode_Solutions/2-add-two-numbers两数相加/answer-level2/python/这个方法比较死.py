```
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        i,j =1,1
        self.result = 0
        result1,result2 = 0,0
        temp1 = ListNode(-1)
        temp2 = temp1
        while l1:
            result1 = i*l1.val + result1
            i = i* 10
            l1 = l1.next
        while l2:
            result2 = j*l2.val + result2
            j = j* 10
            l2 = l2.next
        self.result = result1 + result2
        if self.result == 0:
            return ListNode(0)
        while self.result != 0:
           temp = ListNode(self.result%10)
           temp1.next = temp
           temp1 = temp1.next
           self.result = int(self.result /10)
        return temp2.next
```
