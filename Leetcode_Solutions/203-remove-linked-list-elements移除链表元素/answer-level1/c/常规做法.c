### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* q=head;
    struct ListNode* p;
    if(q==NULL) return NULL;
    int flag=0;
       while(q!=NULL){
           if(q->val==val&&q==head){
               head=head->next;
               q=head;
               continue;
           }
          if(q->val==val&&q!=head){
               p->next=q->next;
               flag=1;
           }
           if(q==head) {
               q=q->next;
               p=head;
           }
           else{
               if(flag){
              q=q->next;
              flag=0;
               }
               else{
                  q=q->next;
                  p=p->next;
               }
            }
           }
           return head;
    }
```