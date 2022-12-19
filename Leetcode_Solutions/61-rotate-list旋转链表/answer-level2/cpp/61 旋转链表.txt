解题思路：参考官方题解


```
class Solution {
public:
    //思路：
    ListNode* rotateRight(ListNode* head, int k) {
        //
        if(head==NULL||head->next==NULL) return head;//特殊情况
        

        ListNode* old_tail=head;
        int length=1;
        for(;old_tail->next!=NULL;length++)
        {
            old_tail=old_tail->next;
        }
        old_tail->next=head;

        ListNode* new_tail=head;
        int i=0;
        for(;i<length-k%length-1;i++)
        {
            new_tail=new_tail->next;
        }
        ListNode* new_head=new_tail->next;
        new_tail->next=NULL;        
        
        return new_head;
    }
};
```
