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
    struct ListNode * cur=head;
    struct ListNode * before=NULL;
    while(cur!=NULL){
        if(cur->val==val){
            if(before==NULL){
                head=cur->next;
                cur=cur->next;
            }
            else{
                before->next=cur->next;
                cur=cur->next;
            }
        }
        else{
            before=cur;
            cur=cur->next;
        }
    }

    return head;
    
}
```