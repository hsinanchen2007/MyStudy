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


struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    typedef struct ListNode  node;
    node *last;
//迭代
    last = reverseList(head->next);
    head->next->next = head;
    head->next =   NULL;
    return last;
}
```