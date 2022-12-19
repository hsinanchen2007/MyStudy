### 解题思路


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * }Node;
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    
    struct ListNode* l3;
    struct ListNode* head;
    l3=(struct ListNode*)malloc(sizeof(struct ListNode));
    head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head =l3;
    while(l1!=NULL&&l2!=NULL){
        if(l1->val<l2->val){
            l3->next=l1;
            l3=l3->next;
            l1=l1->next;
        }else{
            l3->next=l2;
            l3=l3->next;
            l2=l2->next;
        }
    }
    if(l1==NULL){
        l3->next=l2;
    }
    if(l2==NULL){
        l3->next=l1;
    }
    return head->next;
    
}


```