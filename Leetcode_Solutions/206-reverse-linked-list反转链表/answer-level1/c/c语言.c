### 解题思路
注意是没有头结点的，这点一定注意

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
    struct ListNode *p,*rear;
    int len=0;
    int i;
    p=head;
    if(head==NULL||head->next==NULL){
        return head;
    }
    while(p!=NULL){
        len++;
        p=p->next;
    }
    rear=head;
    while(rear->next!=NULL){
        rear=rear->next;
    }
    for(i=1;i<=len-1;i++){
        p=head;
        head=head->next;
        p->next=rear->next;
        rear->next=p;
    }
    return head;
}
```