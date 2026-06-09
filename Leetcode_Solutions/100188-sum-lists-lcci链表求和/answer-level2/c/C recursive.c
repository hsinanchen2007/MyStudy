```
void helper(struct ListNode *pre, struct ListNode* l1, struct ListNode* l2, int carry)
{
  if(l1 == NULL && l2 == NULL && carry == 0) return;

  struct ListNode *cur = malloc(sizeof(struct ListNode));
  cur->next = NULL;
  pre->next = cur;

  int val = carry;

  if(l1) 
  {
    val += l1->val;
    l1 = l1->next;
  }

  if(l2)
  {
    val += l2->val;
    l2 = l2->next;
  } 

  cur->val = val % 10;

  helper(cur, l1, l2, val / 10);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

  struct ListNode fake;
  fake.next = NULL;

  helper(&fake, l1, l2, 0);

  return fake.next;
}
```
