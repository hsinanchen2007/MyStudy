### 解题思路
直接建立一个反转链表再比较

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){//发现这里给的都是没有头结点的
    struct ListNode *p,*q,*add,*now;
    if(head==NULL){
        return true;
    }
    p=(struct ListNode *)malloc(sizeof(struct ListNode));
    p->val=0;
    p->next=NULL;
    q=head;
    while(q!=NULL){
        add=(struct ListNode *)malloc(sizeof(struct ListNode));
        add->val=q->val;
        add->next=p->next;
        p->next=add;
        q=q->next;
    }
    q=head;
    now=p->next;
    while(q!=NULL&&now!=NULL){
        if(q->val!=now->val){
            return false;
        }
        q=q->next;
        now=now->next;
    }
    return true;
}
```