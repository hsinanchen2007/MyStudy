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


struct ListNode* oddEvenList(struct ListNode* head){
    if(head==NULL){
        return NULL;
    }
    struct ListNode *odd = head;
    struct ListNode *even = head->next;
    struct ListNode *even_head = even;

    while(even!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = even_head;
    return head;
}
```