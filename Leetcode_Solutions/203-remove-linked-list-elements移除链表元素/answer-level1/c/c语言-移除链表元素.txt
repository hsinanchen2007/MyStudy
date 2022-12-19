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
    struct ListNode *pre=NULL,*p=head,*r;
    while(p!=NULL){
        r=p->next;
        if(p->val==val){
            if(pre==NULL)head=head->next;
            else pre->next=p->next;
          
        }
        else pre=p;
        p=r;
    }
    return head;
}
```