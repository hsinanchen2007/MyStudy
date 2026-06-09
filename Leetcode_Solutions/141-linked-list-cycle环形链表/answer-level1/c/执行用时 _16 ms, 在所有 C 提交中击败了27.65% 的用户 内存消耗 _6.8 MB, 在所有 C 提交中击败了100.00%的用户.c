/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head==NULL||head->next==NULL){
        return false;
    }
    struct ListNode *p=head;
    struct ListNode *q=head;
    while(p!=NULL&&q!=NULL){
        if(p->next==NULL||q->next==NULL){
            return false;
        }
        p=p->next;
        q=q->next->next;
        if(p==q){
            return true;
        }
    }
    return false;
}