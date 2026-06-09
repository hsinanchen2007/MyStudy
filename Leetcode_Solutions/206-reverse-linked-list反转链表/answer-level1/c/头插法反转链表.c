### 解题思路
头插法建表
### 代码
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode * p,*q;
    if(head==NULL);
    else{
        p=head->next;
        head->next=NULL;
        while(p!=NULL){
             q=p->next;
             p->next=head;
             head=p;
             p=q;  
        }
    }
    return head;
}
