### 解题思路
将后面若干个节点挪到前面来即可

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head==NULL){
        return head;
    }
    int len=0,i=0,j=0;
    ListNode *p=head,*pre=NULL,*tail=NULL;
    while(p!=NULL){
        tail=p;
        p=p->next;
        len++;
    }
    k=k%len;
    if(k==0){
        return head;
    }
    p=head;
    i=len-k;
    while(j<i){
        pre=p;
        p=p->next;
        j++;
    }
    pre->next=NULL;
    tail->next=head;
    return p;
}
```