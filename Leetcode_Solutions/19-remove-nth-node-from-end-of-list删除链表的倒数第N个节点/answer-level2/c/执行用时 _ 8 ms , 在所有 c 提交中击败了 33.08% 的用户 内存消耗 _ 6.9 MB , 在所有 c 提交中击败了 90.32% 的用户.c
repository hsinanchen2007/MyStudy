### 解题思路
总共遍历两遍，第一遍先遍历出来链表的长度，之后就好弄了

### 代码

```c
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
   struct ListNode *p=head;
   struct ListNode *q;
    int l=1;
    while(p->next!=NULL){
        p=p->next;
        l++;
    }
    p=head;
    if(l==n){
        head=head->next;
        return head;
    }
    for(int i=1;i<l-n;i++){
        p=p->next;
    }
    p->next=p->next->next;
    return head;
}
```