解题思路： 让重复出现的结点的前一个和后一个相连，以达到剔除的目的
```
typedef struct ListNode ListNode;
struct ListNode* removeDuplicateNodes(struct ListNode* head){
    if(head==NULL||head->next==NULL)
        return head;
    ListNode *cur=head;
    ListNode *pre=NULL;
    ListNode *next=NULL;
    while(cur)
    {
        pre=cur;
        next=cur->next;
        while(next)
        {
            if(cur->val==next->val)
            {
                pre->next=next->next;
            }
            else
            {
                pre=next;
            }
            next=next->next;
        }
        cur=cur->next;
    }
    return head;
}
```
