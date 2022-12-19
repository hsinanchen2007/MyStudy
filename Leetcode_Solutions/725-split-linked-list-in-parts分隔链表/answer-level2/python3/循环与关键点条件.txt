
```python []
class Solution:
    def splitListToParts(self, root: ListNode, k: int) -> List[ListNode]:
        ret = []
        ll=0
        cur = root
        while cur:
            ll+=1
            cur=cur.next
       
        a, b = ll//k, ll%k  

        for i in range(k):
            if root:
                aret = root
                bd = -1 if i < b else 0
                m = a
                while m > bd:
                    pre = root
                    root = root.next
                    m-=1
                pre.next = None
                ret.append(aret)
            else:
                aret = None
                ret.append(aret)
                
        return ret
```