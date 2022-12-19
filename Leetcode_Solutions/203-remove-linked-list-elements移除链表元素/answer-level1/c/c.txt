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


struct ListNode* removeElements(struct ListNode* head, int val){
    if(head==NULL) return NULL;
    struct ListNode*p,*q,*new;
    new=(struct ListNode*)malloc(sizeof(struct ListNode));
    new->next=head;p=new;q=p->next;
    while(q)
    {   
        if(val==q->val)
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }else{
        q=q->next;
        p=p->next;
    }
    }
    return new->next;

}
```