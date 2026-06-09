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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail = head;
    while(l1 && l2){
        if(l1->val > l2->val){
            tail->next = l2;
            l2 = l2->next;
        } else{
            tail->next = l1;
            l1 = l1->next;
        }
        tail = tail->next;
    }
    tail->next = (l1 == NULL)?l2:l1;
    return head->next;  
}
```