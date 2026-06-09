### 解题思路
尾插法归并
两个元素中较小的那个结点链接在l3后面（r->next=p;直接把该结点放在l3的后面，不需每次都创建新结点），且该链表指针和l3的指针都向后移一个，继续比较。
若还有剩余结点，直接把他们链接在l3的尾部
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//l1,l2为有序链表
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p=l1;
    struct ListNode *q=l2;
    struct ListNode *l3=(struct ListNode *)malloc(sizeof(struct ListNode));
    l3->next=NULL;
    struct ListNode *r=l3;
    while(p!=NULL&&q!=NULL){
        if(p->val<=q->val){
            r->next=p;
            p=p->next;
            r=r->next;
        }
        else{
            r->next=q;
            q=q->next;
            r=r->next;
        }
    }
    r->next=NULL;//若两链表都到达末尾，则把最后结点指针域指空
    if(p!=NULL){
        r->next=p;
    }
    if(q!=NULL){
        r->next=q;
    }
    return l3->next;
}
```