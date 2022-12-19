```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));

    struct ListNode* ans = head;
    //ans = head;


    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            head->next = l1;
            l1 = l1->next;
        } else {
            head->next = l2;
            l2 = l2->next;
        }
        head = head->next;
    }
    head->next = l1 == NULL ? l2 : l1;
    return ans->next;
}
```
