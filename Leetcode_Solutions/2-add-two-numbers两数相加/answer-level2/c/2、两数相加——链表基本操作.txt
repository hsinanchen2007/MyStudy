### 解题思路
链表基本操作

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if (!l1 || !l2) {
        return NULL;
    }

    struct ListNode *pResult = NULL; 
    struct ListNode *pNodeTail = NULL;
    int shift = 0;
    do {
        int tmp1 = 0, tmp2 = 0;
        if (l1) {
            tmp1 = l1->val;
            l1 = l1->next;
        } 
        if (l2) {
            tmp2 = l2->val;
            l2 = l2->next;
        } 

        struct ListNode* newNode = (struct ListNode*)calloc(1, sizeof(struct ListNode));
        newNode->val = (tmp1 + tmp2 + shift) % 10;
        shift = (tmp1 + tmp2 + shift) / 10;
        if (!pResult) {
            pResult = newNode;
        } else {
            pNodeTail->next = newNode;
        }
        pNodeTail = newNode;
    } while(l1 || l2 || shift);

    return pResult;
}
```