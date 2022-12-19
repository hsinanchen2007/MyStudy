### 解题思路
创个头，谁小谁先跟着，最后谁还有谁再跟上

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * head=(struct ListNode*)malloc(sizeof(struct ListNode)),*pro=head;
    head->val=0;
    head->next=NULL;
    while(l1&&l2){                       //谁小谁跟上
        if(l1->val<l2->val){
            pro->next=l1;
            pro=pro->next;
            l1=l1->next;
        }
        else{
            pro->next=l2;
            pro=pro->next;
            l2=l2->next;  
        }
    }
    if(l1) pro->next=l1;                  //谁还有谁跟上
    if(l2) pro->next=l2;
    return head->next;
}
```