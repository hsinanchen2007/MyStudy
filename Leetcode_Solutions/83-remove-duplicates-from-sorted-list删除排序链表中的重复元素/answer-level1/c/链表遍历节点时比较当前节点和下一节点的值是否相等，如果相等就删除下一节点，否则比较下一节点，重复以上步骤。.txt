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


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        return head;
    }
    struct ListNode* p=head;
    struct ListNode* q=head;
    while(p!=NULL||q!=NULL){
        if(q->next!=NULL&&p->val==q->next->val){
            q=q->next;
            p->next=q->next;
            q=p;
        }
        else{
            p=p->next;
            q=p;
        }
     
    }
    return head;
}
```