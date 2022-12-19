### 解题思路
头插法建立单链表

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
    struct ListNode *p, *p2;
    if(head==NULL)
        return head;
    p = head->next;
    head->next = NULL;
    while(p)
    {
        p2=p->next;
        p->next = head;
        head = p;
        p = p2;
    }
    return head;
}
```