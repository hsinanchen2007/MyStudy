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
    struct ListNode *pre=NULL,*p=head,*r;
    while(p!=NULL){
        r=p->next;
        if(pre!=NULL){
            //判断是否和前一个数相同
            if(pre->val==p->val){
                //删除p
                pre->next=p->next;
            }
            else pre=p;
        }
        else pre=p;
        p=r;
    }
    return head;
}
```