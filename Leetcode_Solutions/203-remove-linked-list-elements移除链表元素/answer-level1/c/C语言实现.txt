
```C []
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* curr = head, * prev = NULL;
    while (curr){
        if (curr->val == val){
            struct ListNode *p = curr;
            if (NULL == prev){
                head = curr->next;
                curr = head;
            } else{
                curr = curr->next;
                prev->next = curr;
            }
            free(p);
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
```