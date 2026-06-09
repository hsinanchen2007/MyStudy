
Reverse the latter half list then compare with the former.

```
struct ListNode *reverse(struct ListNode* head)
{
  if(head == NULL || head->next == NULL) return head;

  struct ListNode *ret = reverse(head->next);

  head->next->next = head;
  head->next = NULL;

  return ret;
}

bool isPalindrome(struct ListNode* head){

  struct ListNode *fast = head;
  struct ListNode *mid = head;

  while(fast && fast->next)
  {
    fast = fast->next->next;
    mid = mid->next;
  }

  struct ListNode *head2 = reverse(mid);

  while(head && head2)
  {
    if(head->val != head2->val) return 0;
    head = head->next;
    head2 = head2->next;
  }

  return 1;
}
```
