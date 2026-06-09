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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *temp=(struct ListNode*)malloc(sizeof(struct ListNode));
    temp->next=head;
    struct ListNode *p1=temp,*p2=temp;
    while(n--) p1=p1->next;
    while(p1->next!=NULL){
        p2=p2->next;
        p1=p1->next;
    }
    p2->next = p2->next->next;
    return temp->next;
}
```