/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    if(head == NULL) return NULL; 
    while(head && head->val == val){
            struct ListNode* s = head;
            head = s->next;
            free(s);
        }
    if(head == NULL) return NULL;
    struct ListNode* p = head;
    struct ListNode* q = head->next;
    while(p && q){
        if(q->val == val){
            struct ListNode* s = q;
            p->next = q->next;
            q = q->next;
            free(s);
            continue;
        }
        q = q->next;
        p = p->next;
    }
    return head;
}