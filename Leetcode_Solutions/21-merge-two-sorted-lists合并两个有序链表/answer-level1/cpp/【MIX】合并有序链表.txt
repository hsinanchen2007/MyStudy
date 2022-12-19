### 解题思路
循环合并

### 代码

```java []
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1);
        ListNode p = l1, q = l2, r = dummy;
        while(p != null && q != null){
            if(p.val < q.val){
                r.next = new ListNode(p.val);
                p = p.next;
            }
            else{
                r.next = new ListNode(q.val);
                q = q.next;
            }
            r = r.next;
        }

        if(p != null)
            r.next = p;
        if(q != null)
            r.next = q;

        return dummy.next;
    }
}
```
```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        res = ListNode(-1)
        p, q, R = l1, l2, res
        while p != None and q != None:
            if p.val < q.val:
                R.next = ListNode(p.val)
                R = R.next
                p = p.next
            else:
                R.next = ListNode(q.val)
                R = R.next
                q = q.next

        if p != None:
            # R.next = ListNode(p.val)
            # p = p.next
            # R = R.next
            R.next = p

        if q != None:
            # R.next = ListNode(q.val)
            # q = q.next
            # R = R.next
            R.next = q

        return res.next
            
                
```
```c++ []
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p = l1, *q = l2;
        ListNode *res = new ListNode(-1);
        ListNode *r = res;
        
        while(p != NULL && q!=NULL){
            if(p->val < q->val){
                r->next = new ListNode(p->val);
                r = r->next;
                p = p->next;
            }
            else{
                r->next = new ListNode(q->val);
                r = r->next;
                q = q->next;
            }
        }

        if(p != NULL)
            r->next = p;
        if(q != NULL)
            r->next = q;

        return res->next;
    }
};
```