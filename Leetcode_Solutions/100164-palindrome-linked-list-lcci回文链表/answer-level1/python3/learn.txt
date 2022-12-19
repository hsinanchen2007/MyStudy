```
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if head == None:
            return True
        list_01 = [head.val]
        while head.next:
            list_01.append(head.next.val)
            head = head.next
        n = len(list_01)
        i = 0
        j = n -1
        if n == 1:
            return True
        elif (n % 2 == 0):
            while i < n / 2:
                if list_01[i] != list_01[j]:
                    return False
                i += 1
                j -= 1
            return True
        elif (n % 2 == 1):
            while i != j:
                if list_01[i] != list_01[j]:
                    return False
                i += 1
                j -= 1
            return True
```
