### 解题思路
先進入最小位數 從最小位數檢查
當+1沒有超過10就不進一步處理
當+1 等於 10 則 將高一位數也 +1
當有發生時 回傳有進位的 Flag

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def plusOne(self, head: ListNode) -> ListNode:
        def deep(head):
            if head.next == None:
                head.val += 1
                if head.val == 10:
                    head.val = 0
                    return True
                else:
                    return False
            get = deep(head.next)
            if get:
                head.val += 1
                if head.val == 10:
                    head.val = 0
                    return True
                else:
                    return False
        get = deep(head)
        if get :
            head2 = ListNode(1)
            head2.next = head
            return head2
        else:
            return head             

```