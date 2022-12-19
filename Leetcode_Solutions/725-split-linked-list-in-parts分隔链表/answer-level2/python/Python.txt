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
    def splitListToParts(self, root, k):
        ans = [ListNode(None) for _ in range(k)]
        cur = root
        len_root = 0
        while (cur != None):
            len_root = len_root + 1
            cur = cur.next
        size=len_root/k
        mod=len_root%k
        cur=root
        for i in range(k):
            ans[i]=cur
            if mod==0:
                leng=size
            elif mod!=0:
                leng=size+1
                mod=mod-1
            while leng!=0 and cur!=None:
                if leng==1:
                    curr=cur.next
                    cur.next=None
                    cur=curr
                    break
                leng=leng-1
                cur=cur.next
        return ans
```