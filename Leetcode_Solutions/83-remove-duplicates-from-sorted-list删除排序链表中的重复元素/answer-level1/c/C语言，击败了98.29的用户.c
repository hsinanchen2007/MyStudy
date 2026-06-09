注意是有序链表

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//typedef struct ListNode *


struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *p = head;
    struct ListNode *q;
    struct ListNode *tmp;

    while (p!= NULL) {
        q = p->next;
        while (q && q->val == p->val) {
            tmp = q;
            q = q->next;
            free(tmp);
        }
        p->next = q;
        p = p->next;
    }
    return head;
}