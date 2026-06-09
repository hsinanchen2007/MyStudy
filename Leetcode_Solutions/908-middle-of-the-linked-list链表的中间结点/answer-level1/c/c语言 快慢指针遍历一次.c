```c
struct ListNode* middleNode(struct ListNode* head){

    struct ListNode *slow=head;

    struct ListNode *fast=head;

    while(fast)

    {
        if(fast==NULL||fast->next==NULL)
        {
            return slow;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;

}