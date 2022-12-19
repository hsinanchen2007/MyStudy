### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        cur=head
        if cur==None:
            return True
        ans=[]
        while(cur!=None):
            ans.append(cur.val)
            cur=cur.next
        len_ans=len(ans)
        if len_ans==1 or len_ans==0:
            return True
        while len(ans)!=1 and len(ans)!=0:
            l=ans.pop(0)
            r=ans.pop(len(ans)-1)
            if l!=r:
                return False
        return True
```