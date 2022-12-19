```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* p1=head;
        ListNode* p2=head->next;
        while(p1->next!=NULL)
        {
            if(p1->val==p2->val)//重复的情况
            {
                if(p2->next==NULL)
                    p1->next=NULL;
                else
                {
                    p1->next=p2->next;
                    p2=p2->next;
                }
            }
            else//不重复的情况    
            {
                p1=p1->next;
                p2=p2->next;
            }
        }
        return head;
    }
};
```
