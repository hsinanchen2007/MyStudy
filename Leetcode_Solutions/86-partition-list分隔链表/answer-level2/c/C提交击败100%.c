### 解题思路
双指针遍历，最后拼接。

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
    struct ListNode*p1Head=(struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode*p2Head=(struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode*p1=p1Head;
    struct ListNode*p2=p2Head;
    struct ListNode*p=head;

    while(p){
        if(p->val<x){
            p1->next=p;
            p1=p;
        }
        else{
            p2->next=p;
            p2=p;
        }
        p=p->next;
    }
  p2->next=NULL;
    p1->next=p2Head->next;
    return p1Head->next;

}
```