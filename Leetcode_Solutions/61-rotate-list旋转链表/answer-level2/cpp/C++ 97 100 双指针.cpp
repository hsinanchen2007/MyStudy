

```
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode *p , *q, *r;
        p = q = head;
        for(int i = 0 ; i < k ; i++){  //实质为倒数K位拼接到链表头
            if(q->next!=NULL){
                q=q->next;
            } 
            else {                  
                k = k%(i+1)+1;
                i = 0 ;
                q=head;             //成环
            }
        }
        while(q->next!=NULL){
            if(p->next==NULL) p=head;
            else p=p->next;
            q=q->next;
        }
        q->next = head;
        r = p->next ;
        p->next = NULL;
        return r;
    }
};
```




![image.png](https://pic.leetcode-cn.com/805bb02a4be14aff4fb9b0992513a906ecbf2adae4e4fe8eead962cc3a3b3912-image.png)
