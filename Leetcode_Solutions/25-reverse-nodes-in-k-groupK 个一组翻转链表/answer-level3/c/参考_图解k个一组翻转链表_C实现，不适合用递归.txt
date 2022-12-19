```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode * reverse(struct ListNode *head) {
    struct ListNode * pre = NULL;
    struct ListNode * curr = head;
    while (curr != NULL) {
        struct ListNode *next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* pre = dummy;
    struct ListNode* end = dummy;

    while (end->next != NULL) {
        for (int i = 0; i < k && end != NULL; i++) end = end->next;
        if (end == NULL) break;
        struct ListNode* start = pre->next;
        struct ListNode* next = end->next;
        end->next = NULL;
        pre->next = reverse(start);
        start->next = next;
        pre = start;

        end = pre;
    }
    return dummy->next;
}

```
