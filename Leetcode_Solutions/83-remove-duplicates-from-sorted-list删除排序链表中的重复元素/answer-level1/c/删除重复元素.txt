### 解题思路
此处撰写解题思路
筛选不重复节点到新表
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *p,*new,*s,*q;
    if (head == NULL) {
        return NULL;
    }
    
    new=(struct ListNode*)malloc(sizeof(struct ListNode));
    new->val=head->val;
    new->next=NULL;
    
    q=new;
    for(p=head;p!=NULL;p=p->next)
    {
        
        if((p->val!=new->val)&&(p->val>new->val))
        {   
            s=(struct ListNode*)malloc(sizeof(struct ListNode));
            s->val=p->val;
            s->next=new->next;
            new->next=s;
            new=new->next;
        }
        
    }
    return q;
}
```