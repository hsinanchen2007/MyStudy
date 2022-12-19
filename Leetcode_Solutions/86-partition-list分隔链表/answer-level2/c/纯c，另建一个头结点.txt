### 解题思路
另建一个头结点，遍历原链表将小于x的结点用尾插法插入结点；
遍历完后，将剩余结点连接在new链表上

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
    struct ListNode* newhead=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* oldhead=(struct ListNode*)malloc(sizeof(struct ListNode));
    oldhead->next=head;
    struct ListNode* r=newhead;
    struct ListNode* p=oldhead->next;
    struct ListNode* pre=oldhead;

    while(p)
    {
        if(p->val<x)
        {
            pre->next=p->next;
            r->next=p;
            p=p->next;
            r=r->next;
            r->next=NULL;
            continue;
        }
        p=p->next;
        pre=pre->next;
    }
    
    r->next=oldhead->next;
    free(oldhead);
    return newhead->next;
}
```