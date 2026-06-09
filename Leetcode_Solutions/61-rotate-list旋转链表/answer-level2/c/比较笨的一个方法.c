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

int len(struct ListNode* head){
    int count=0;
    struct ListNode *p=head;
    while(p!=NULL){
        p=p->next;
        count++;
    }
    return count;
}
struct ListNode* rotateRight(struct ListNode* head, int k){
    //思路很简单，每次移动一位，移动k次即可
    int i=1;
    int time;
    struct ListNode *p,*q;
    if(head==NULL||head->next==NULL){
        return head;
    }
    time=k%(len(head));
    for(i=1;i<=time;i++){
        p=q=head;
        while(p->next!=NULL){
            q=p;
            p=p->next;
        }
        p->next=head;
        head=p;
        q->next=NULL;
    }
    return head;
}
```