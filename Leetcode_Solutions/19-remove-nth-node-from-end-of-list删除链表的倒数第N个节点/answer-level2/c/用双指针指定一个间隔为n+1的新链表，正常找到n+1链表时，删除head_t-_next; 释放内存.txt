/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* head_t;
    struct ListNode* tail;
    struct ListNode* del_node;
    int index = 0;

    head_t = head;
    tail = head;

    if (tail->next == NULL) {
        free(tail);
        return NULL;
    }

    while (tail != NULL) {
        if (index == n+1) {
            head_t = head_t->next;
        } else {
            index++;
        }
        tail = tail->next;
    }

    if (index == n+1) {
        del_node = head_t->next;
        head_t->next = del_node->next;
    } else if (index == n) {
        del_node = head;
        head = head->next;
    } else {
        return NULL;
    }

    free(del_node);

    return head;
}