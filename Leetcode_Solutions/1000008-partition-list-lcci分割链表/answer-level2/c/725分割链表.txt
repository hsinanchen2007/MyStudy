```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode* node;

struct ListNode* partition(struct ListNode* head, int x){
    if (head == NULL) return head;
    node l1 = NULL;
    node l2 = NULL;
    node l3 = NULL;
    while (head !=  NULL) {
        node temp = (node) malloc(sizeof(struct ListNode));
        temp->val = head->val;
        temp->next = NULL;
        if (head->val < x) {
            if (l1 == NULL) {
                l1 = temp;
                l3 = temp;
            } else {
                temp->next = l1;
                l1 = temp;
            }
        } else {
            if (l2 == NULL) {
                l2 = temp;
            } else {
                temp->next = l2;
                l2 = temp;
            }
        }
        head = head->next;
    }
    if (l3 != NULL) {
       l3->next = l2; 
    } else {
        l1 = l2;
    }
    return l1;
}
```
