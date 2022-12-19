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
    int val_last = 0;
    struct ListNode * p = head;
    struct ListNode * p_last  = NULL;
    struct ListNode * p_new = NULL;
    int tmp_val = 0;

    if(head == NULL){
        return head;
    }
    else if(head->next == NULL){
        return head;
    }
    else{
        while(p){
            if(p->next != NULL){
                if(p->next->val != p->val){
                    p_last = p;
                    if(p_new == NULL){
                        p_new = p;
                    }
                    p = p->next;
                }
                else{
                    tmp_val = p->val;                                    
                    while(p && p->val == tmp_val){
                        p = p->next;
                    }
                    if(p_last){
                        p_last->next= p;                    
                    }
                }     
            }
            else{
                if(p_new == NULL){
                    p_new = p;
                }
                break;
            }                                       
        }
        return p_new;
    }
}
```