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


struct ListNode* rotateRight(struct ListNode* head, int k){
    if (head == NULL){
        return head;
    }    
    int sz = 0;
    struct ListNode* curr = NULL;
    struct ListNode* last = NULL;
    curr = head;
    while (curr != NULL){
        sz++;
        last = curr;
        curr = curr->next;
    }
    k %= sz;
    if (k == 0){
        return head;
    }
    int mv = sz - k;
    curr = head;
    for (int i = 1; i < mv; i++){
        curr = curr->next;
    }
    last->next = head;
    head = curr->next;
    curr->next = NULL;
    return head;
    }
```