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
struct ListNode* reverseList(struct ListNode* head){

// 1. 
    struct ListNode * p = head;
    struct ListNode * tmp;
    struct ListNode * newList = NULL;
    if(head == NULL){
        return head;
    }
    else if(head->next == NULL){
        return head;
    }
    else{
        while(p){
            tmp = p->next;
            p->next = newList;
            newList = p;
            p = tmp;
        }
        return newList;
    }
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    int tmp_num = 1;
    struct ListNode * tmp_front = head;
    struct ListNode* tmp_next = NULL;
    struct ListNode * tmp_last = NULL;
    struct ListNode * p = head;
    struct ListNode * p_new = NULL;
    struct ListNode * tmp_new = NULL;
    
    if(head == NULL){
        return head;
    }
    else if(head->next == NULL || k == 1){
        return head;
    }
    else{
        while(p != NULL){
            if(tmp_num % k == 1){
                tmp_front = p;     
                p = p->next;                     
            }
            else if(tmp_num % k == 0){
                if(tmp_last){
                    tmp_last->next = p;
                }

                tmp_next = p->next;
                p->next = NULL;
                tmp_new = reverseList(tmp_front);
                tmp_last = tmp_front;
                //tmp_front->next = tmp_next;                
                if(tmp_num == k){
                    p_new = tmp_new;
                }
                
                p = tmp_next;
            }
            else{
                p = p->next;                
            }
            tmp_num ++;
        }
        if((tmp_num - 1) % k != 0){
            if(tmp_last == NULL){
                p_new = head;
            }
            else{
                tmp_last->next = tmp_front;
            }
        }
        return p_new;
    }    
}
```