```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *prefix = (struct ListNode *)malloc(sizeof(struct ListNode));
    prefix->val  = 0;
    prefix->next = head;
    
    struct ListNode *pre = prefix;
    
    while (pre->next) {
        struct ListNode *s = pre->next;
        struct ListNode *t = s->next;
        if (!t) break;
        
        pre->next = t;
        s->next = t->next;
        t->next = s;
        
        pre = s;
    }

    pre = prefix->next;
    free(prefix);
    
    return pre;
}
```
