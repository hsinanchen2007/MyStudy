模仿大佬的解法

```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL,*p1=l1,*p2=l2,*p=NULL;
        int b=0;
        while(NULL!=p1||NULL!=p2||b>0)
        {
            ListNode* a=new ListNode(0);
            p1=(NULL!=p1)?(b+=p1->val,p1->next):(b+=0,p1);
            p2=(NULL!=p2)?(b+=p2->val,p2->next):(b+=0,p2);
            a->val=b%10;
            b=b/10;
            p=(NULL==head)?(head=a,head):(p->next=a,p->next);   
        }
        return head;
    }
};
```
