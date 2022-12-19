### 解题思路
简单合并两个有序链表
1、比较l1、l2初结点的val值，小于等于的为基链，设为p（使用另一个指针res保存），q=p->next
2、若r大于等于p，且r小于等于q，也把r加入p后面，r往后移，
3、若r大于q，则，p、q往后移，
4、之后再将r后面剩下的结点接入p后方

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p,*q,*r,*res,*temp;
    
    if(l1==NULL || l2==NULL){
        if(l1)
            return l1;
        else
            return l2;
    }//排除链表为空的情况

    if(l1->val > l2->val){//用三元运算符的条件表达式比较好，但是不太会用
        p=l2;
        r=l1;
    }
    else{
        p=l1;
        r=l2;
    }

    res=p;//保存原结点
    
    while(p->next!=NULL && r!=NULL){//同时遍历两个链表
        q=p->next;
        if(r->val>=p->val && r->val<=q->val){
            temp = r->next;
            r->next=p->next;
            p->next=r;//将r插入p后面
            p=r;//继续基础链的后推
            r=temp;
        }
        else{//若不符合插入条件则后推一个结点
            p=p->next;
        }
    }

    if(r)//将后续的链表连上
        p->next=r;
    
    return res;
}
```