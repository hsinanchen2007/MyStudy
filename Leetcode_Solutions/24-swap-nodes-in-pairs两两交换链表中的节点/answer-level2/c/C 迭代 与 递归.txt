### 解题思路

递归简洁

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// struct ListNode* swapPairs(struct ListNode* head){
//     struct ListNode *L = (struct ListNode *)malloc(sizeof(struct ListNode));
//     L->next = head;
//     struct ListNode *pre = L;
//     struct ListNode *p = pre->next;
//     struct ListNode *q = p? p->next: NULL;

//     while (p && q) {
//         p->next = q->next;
//         q->next = p;
//         pre->next = q;
//         pre = p;
//         p = pre->next;
//         q = p? p->next: NULL;
//     }

//     head = L->next;
//     free(L);
//     return head;
// }

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *p = head->next;
    head->next = swapPairs(p->next);
    p->next = head;
    
    return p;
}
```