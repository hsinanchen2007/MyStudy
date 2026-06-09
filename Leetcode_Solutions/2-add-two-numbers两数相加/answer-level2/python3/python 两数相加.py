```javascript []
console.log('Hello world!')
```
```python []
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:

        l1_lenth, l2_lenth = 1, 1
        temp1, temp2 = l1, l2
        while temp1.next != None:
            l1_lenth += 1
            temp1 = temp1.next
        while temp2.next != None:
            l2_lenth += 1
            temp2 = temp2.next

        temp1, temp2 = l1, l2
        flag = 0
        if l1_lenth >= l2_lenth:
           
            for i in range(l2_lenth):
                a = temp1.val + temp2.val
                temp1.val = (a + flag) % 10
                flag =  (a + flag) // 10
        
                if i != l2_lenth-1:
                    temp1 = temp1.next
                    temp2 = temp2.next
        
            if flag > 0:
         
                if l1_lenth == l2_lenth:
                    temp1.next = ListNode(1)
                else:
                    temp1 = temp1.next
                    for i in range(l1_lenth-l2_lenth):
                        a = temp1.val
                        temp1.val = (a + flag) % 10
                        flag =  (a + flag) // 10
                        if i != l1_lenth-l2_lenth-1:
                            temp1 = temp1.next
            if flag > 0:
                temp1.next = ListNode(1)
            return l1

        else:
            for i in range(l1_lenth):
                a = temp1.val + temp2.val
                temp2.val = (a + flag) % 10
                flag =  (a + flag) // 10
                
                if i != l1_lenth-1:
                    temp1 = temp1.next
                    temp2 = temp2.next
        
            if flag > 0:
                if l2_lenth == l1_lenth:
                    temp2.next = ListNode(1)
                else:
                    temp2 = temp2.next
                    for i in range(l2_lenth-l1_lenth):
                        a = temp2.val
                        temp2.val = (a + flag) % 10
                        flag =  (a + flag) // 10
                        if i != l2_lenth-l1_lenth-1:
                            temp2 = temp2.next
            if flag > 0:
                temp2.next = ListNode(1)
            
            return l2
```
```ruby []
puts 'Hello world!'
```
