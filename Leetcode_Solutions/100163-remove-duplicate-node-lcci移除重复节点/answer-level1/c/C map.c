```
struct ListNode* removeDuplicateNodes(struct ListNode* head){
  
  char *map = malloc(20001);
  memset(map, 0, 20001);
  
  struct ListNode *pre;
  struct ListNode *cur = head;
  
  while(cur)
  {
    if(map[cur->val] == 0) 
    {
      map[cur->val] = 1;
      pre = cur;
    }
    else 
    {
      assert(pre);
      pre->next = cur->next;  // delete this duplicated node
    }
    
    cur = cur->next;
  }
  
  free(map);

  return head;
}
```
