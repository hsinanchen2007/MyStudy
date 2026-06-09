
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/***
思路：遍历两个链表，比较两个链表的值，哪个较小就存入新链表，并将该链表取下一个，
直到一个链表遍历完。如果第二个链表还有值，就将第二个链表接到新链表后即可
**/

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    struct ListNode *L = (struct ListNode*)malloc(sizeof(struct ListNode));
    L->val = 0;
    L->next = NULL;
    
    struct ListNode* cur = L;
    int carry = 0;
    //先遍历第一个链表
    while(l1 != NULL){
        struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode));
        //第二个链表不为空，比较两个链表的值，哪个小，就存入新链表
        if(l2 != NULL){
            if(l1->val < l2->val){  
                p->val = l1->val;
                p->next = NULL;
                l1 = l1->next;
            }else{
                p->val = l2->val;

                p->next = NULL;
                l2 = l2->next;   
            } 
        }else{  //第二个链表为空时，直接将此链表添加到新链表后即可
            p->val = l1->val;
            p->next = NULL;
            l1 = l1->next;
        }
        cur->next = p;
        cur = cur->next;
    }
    //第一个链表遍历完，第二个还有值
    while(l2 != NULL){
        struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->val = l2->val;
        p->next = NULL;
        l2 = l2->next;
        cur->next = p;
        cur = cur->next;
    }
    return L->next;
}


```
