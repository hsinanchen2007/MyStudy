### 解题思路
三个指针分别记录cur、head、next，循环往下走，让head->next = cur;cur = head;head = next即三个指针都往后走一步，最后注意head->next=cur链上前面的

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
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode *cur = NULL;
    struct ListNode *next = head->next;
    while(head->next != NULL){
        head->next = cur;
        cur = head;
        head = next;
        next = head->next;
    }
    head->next = cur;
    return head;
}
```