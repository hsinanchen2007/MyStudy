### 解题思路
以后取第k个
注意从1开始计数
注意链表操作
leetcode的链表从来都是不带头的
带头的易于操作

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
int kthToLast(struct ListNode* head, int k){
    ListNode*p=(ListNode*)malloc(sizeof(ListNode));
    p->next=NULL;
    ListNode*q=head,*t=q;
    while(q!=NULL){
        t=q;
        q=q->next;
        t->next=p->next;
        p->next=t;
    }
    int i=0;
    while(i<k){
        p=p->next;
        i++;
    }
    return p->val;
}
```