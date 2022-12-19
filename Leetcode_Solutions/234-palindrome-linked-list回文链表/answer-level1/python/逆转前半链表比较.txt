### 解题思路


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if head==None or head.next == None:
            return True
        pre = head
        ne = head.next
        count = 2
        while ne.next!= None:
            pre = ne
            ne = ne.next
            count += 1
        if count%2==1:
            stop = count//2
            flag = 1
        elif count%2==0:
            stop = count//2
            flag = 0
        pre = None
        cur = head
        ne = head
        #print(count)
        #stop -= 1
        #print(stop)
        while stop!=0:
            ne = cur.next
            cur.next = pre 
            pre = cur
            cur = ne
            stop -= 1
        #print(pre)
        if flag == 1:
            right = cur.next
        elif  flag == 0:
            right = cur
        #print(right)
        while pre != None and right != None:
            if pre.val == right.val:
                pre = pre.next
                right = right.next
            else:
                return False
        else:
            if pre==None and right == None:
                return True
            else:
                return False



```