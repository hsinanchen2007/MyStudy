```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode *tmp = NULL;
    struct ListNode *prefix = (struct ListNode *)malloc(sizeof(struct ListNode));
    prefix->val  = 0;
    prefix->next = NULL;
    
    for(int i=0; i<listsSize; i++) {
        struct ListNode *p = prefix;
        struct ListNode *q = lists[i];
        
        // 将每个lists[i] 合并到p
        while (p->next && q) {
            if  ( q->val < p->next->val ) {
                tmp = q->next;
                q->next = p->next;
                p->next = q;
                
                q = tmp;
            }
            p = p->next;
        }
        
        if (q) { p->next = q; }
    }

    tmp = prefix->next;
    free(prefix);
    return tmp;
}
```
