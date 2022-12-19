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
    struct ListNode * Prev,*Temp;
    Prev=NULL;
    while(head)
    {
        Temp=head->next;
        head->next=Prev;
        Prev=head;
        head=Temp;
    }
    return Prev;
}
```