```
// return kth to last of current node
int helper(struct ListNode* head, const int k, int *ret)
{
  if(head == NULL) return 0;

  int kth = helper(head->next, k, ret) + 1;

  if(k == kth) *ret = head->val;

  return kth;
}

int kthToLast(struct ListNode* head, int k){

  int ret = 0;

  (void)helper(head, k, &ret);

  return ret;
}
```
