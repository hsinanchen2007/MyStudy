# 1. 迭代

```
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *p,*q;
    if(!head) return NULL;    
    p=head;
    q=head->next;
    while(q)
    {
      if(head->val==q->val)
        {
            head->next=q->next;
            free(q);
            q=head->next;
        }
      else
      {
          head=head->next;
          q=q->next;
      }
    }
    head=p;
    return head;
   }
```


# 2. 递归

```
struct ListNode* deleteDuplicates(struct ListNode* head){
   if(!head||!(head->next)) return head;    

   head->next= deleteDuplicates(head->next);
   return (head->val==head->next->val)?(head->next):(head);
}
```
3.
```
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *p,*q;
    if(!head||!(head->next)) return head;    
    p=head;
    q=head->next;
    while(q)
    {
      if(head->val==q->val)
        {
            q=q->next;
        }
      else
      {
          head->next=q;
          head=q;
          q=q->next;
      }
    }
    head->next=NULL;
    head=p;
    return head;
   }
```
