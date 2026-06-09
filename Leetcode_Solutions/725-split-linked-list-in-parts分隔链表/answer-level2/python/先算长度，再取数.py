### 解题思路
先算每一部分的长度，然后对应取长度

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def splitListToParts(self, root, k):
        """
        :type root: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        #先计算长度
        length=0
        bak_root=root
        while bak_root:
            length+=1
            bak_root=bak_root.next
        # print length

        step=[length/k for _ in range(k)]
        pre=length%k
        for i,n in enumerate(step[:pre]):
            step[i]+=1
        # print step

        result=[]
        while step:
            # print root.val if root else -1
            nowstep=step.pop(0)
            # print nowstep
            newlink=ListNode(root.val) if root else None
            start=newlink
            # print root.val if root else -1
            # print '___________35_____________'
            while nowstep-1:
                nowstep-=1
                if not root:
                    newlink=None
                    break
                newlink.next=ListNode(root.next.val) if root.next else None
                newlink=newlink.next
                root=root.next
                # print root.val if root else str(-1)+'41 line'
            result.append(start)

            root=root.next if root else None
        return result
                
            
```