```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    if(head == NULL) {
        return NULL;
    }
    struct ListNode *temp1,*temp2,*p1,*p3;
    struct ListNode *p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    p2->next = head;
    p1 = p2;
    while(p1 != NULL) {
        temp1 = p1;
        if(p1->next == NULL) break;
        p1 = p1->next;
        if(p1->next == NULL) break;
        temp2 = p1->next;
        if(temp1->next == NULL) break;
        temp1->next = temp2;
        //if(temp2->next == NULL) break;
        p3 = temp2->next;
        temp2->next = p1;
        if(p1->next == NULL) break;
        p1->next = p3;
    }
    return p2->next;
}
```
