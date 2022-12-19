```
struct ListNode* partition(struct ListNode* head, int x){

  struct ListNode beforeFake;
  beforeFake.next = NULL;
  struct ListNode *beforeTail = &beforeFake;

  struct ListNode afterFake;
  afterFake.next = NULL;
  struct ListNode *afterTail = &afterFake;

  // divid
  while(head)
  {
    struct ListNode *next = head->next;
    head->next = NULL;

    if(head->val < x)
    {
      beforeTail->next = head;
      beforeTail = head;
    }
    else
    {
      afterTail->next = head;
      afterTail = head;
    }

    head = next;
  }

  // merge
  beforeTail->next = afterFake.next;

  return beforeFake.next;
}

```
