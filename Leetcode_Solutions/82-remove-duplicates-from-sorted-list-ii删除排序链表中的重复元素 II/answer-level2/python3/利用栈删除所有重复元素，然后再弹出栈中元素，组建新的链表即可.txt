### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        #如果链表为空
        if head==None:
            return head
        stack=[]
        p=head
        stack.append(p)
        record,count=p.val,0
        p=p.next
        #非重复元素进栈
        while p:
            if p.val==record:
                while p:
                    if p.val==record:
                        p=p.next
                    else:
                        break
                stack.pop()
                if p:
                    record=p.val
                    stack.append(p)
                    p=p.next
            else:
                record=p.val
                stack.append(p)
                p=p.next
        if stack==[]:
            return None
        else:
            while stack:
                count += 1
                if count == 1:
                    p = stack.pop()
                    p.next = None
                    l = p
                else:
                    p = stack.pop()
                    p.next = l
                    l = p
            return l
```