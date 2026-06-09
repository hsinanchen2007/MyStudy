/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* beh, * pre;

    if((head == NULL) || (head->next == NULL))
    {
        return head;
    }

    beh = head;
    pre = beh->next;

    while(pre != NULL)
    {
        if(pre->val == beh->val)
        {
            pre = pre->next;
            beh->next = pre;
        }
        else
        {
            pre = pre->next;
            beh = beh->next;
        }
    }

    return head;
}