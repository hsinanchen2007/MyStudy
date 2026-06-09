```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    int changelen = n-m +1;
    int i = 0;
    struct ListNode* newcode = (struct ListNode*)calloc(1,sizeof(struct ListNode) );
    struct ListNode* bakcode = (struct ListNode*)calloc(1,sizeof(struct ListNode) );
    struct ListNode* precode = NULL;
    struct ListNode* behcode = (struct ListNode*)calloc(1,sizeof(struct ListNode) );
    struct ListNode* newhead = (struct ListNode*)calloc(1,sizeof(struct ListNode) );
    newhead = head;
    while (head != NULL && --m)
    {
       precode = head;
       head = head->next;
       //printf("1%p %p %p\n",precode,head,head->next);
    } 
    behcode = head;

    while(head != NULL && changelen > 0)
    {
        changelen--;
        bakcode = head->next;
        head->next = newcode;
        newcode = head;
        head = bakcode;
      //  printf("2%p %p %p %p\n",bakcode,head->next,newcode,head);
    }

    behcode->next = head;
    if(precode == NULL)
    {
        newhead = newcode;
    }
    else
    {
        precode->next = newcode;
    }
    
    return newhead;
}
```