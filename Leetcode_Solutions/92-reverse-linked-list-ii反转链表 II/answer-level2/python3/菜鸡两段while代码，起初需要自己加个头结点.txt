![image.png](https://pic.leetcode-cn.com/baa93feaa72da3337da07cf35b54a9dded5861d897a68024ec0daca44ad5dd0c-image.png)

```
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        root=ListNode(None)
        root.next=head
        head=root
        i=1
        while i<m:
            root=root.next
            i+=1
        p_middle_next=p1=p2=root.next
        while i<=n:
            tmp=p2.next
            p2.next=p1
            p1=p2
            p2=tmp
            i+=1
        root.next=p1
        p_middle_next.next=p2
        return head.next
```
