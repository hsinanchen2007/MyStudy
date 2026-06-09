### 解题思路
cur指针用来确保cur之前的节点全部小于x，P和pre指针用来遍历

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next=head;
    struct ListNode* cur=dummy;
    while(cur->next&&cur->next->val<x)
        cur=cur->next;
    struct ListNode* pre=cur;
    struct ListNode* p=cur->next;
    while(p){
        if(p->val>=x){
            pre=p;
            p=p->next;
        }
        else{
            pre->next=p->next;
            p->next=cur->next;
            cur->next=p;
            p=pre->next;
            cur=cur->next;
        }
    }
    return dummy->next;
}
```