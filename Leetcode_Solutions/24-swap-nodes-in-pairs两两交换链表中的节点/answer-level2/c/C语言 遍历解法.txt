```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *ptr = dummy;
    struct ListNode *p1 = NULL;
    struct ListNode *p2 = NULL;
    struct ListNode *p3 = NULL;
    struct ListNode *p4 = NULL;

    while(ptr != NULL && ptr->next != NULL && ptr->next->next != NULL) {
        p1 = ptr;
        p2 = ptr->next;
        p3 = ptr->next->next;
        p4 = ptr->next->next->next;

        p1->next = p3;
        p3->next = p2;
        p2->next = p4;    
         

        ptr = ptr->next->next;

    }
   
    return dummy->next;


}
```
