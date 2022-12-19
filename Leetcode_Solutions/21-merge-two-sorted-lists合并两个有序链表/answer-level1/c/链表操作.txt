### 解题思路
表头结点的链表操作
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = NULL;
    int val = 0;
    struct ListNode *tmp = head;
    while(l1 || l2){
        if(l1 && l2 && l1->val < l2->val)       { val = l1->val; l1 = l1->next; }
        else if(l1 && l2 && l1->val >= l2->val) { val = l2->val; l2 = l2->next; }
        else if(l1 == NULL)                     { val = l2->val; l2 = l2->next; }
        else if(l2 == NULL)                     { val = l1->val; l1 = l1->next; }

        struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
        q->next = NULL;
        q->val = val;
        while(tmp->next){
            tmp = tmp->next;
        }

        tmp->next = q;
    }

    return head->next;
}
```