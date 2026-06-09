### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    
    struct ListNode* prehead = (struct ListNode*)malloc(sizeof(struct ListNode));
    prehead->next = head;
    struct ListNode* p0 = prehead;
    struct ListNode* p1 = head;
    struct ListNode* p2 = NULL;
    while(p1 && p1->next){
        p2 = p1->next;
        p1->next = p2->next;
        p2->next = p1;
        p0->next = p2;
        p0 = p1;
        p1 = p1->next;
    }
    head = prehead->next;
    free(prehead);
    return head;
}
```