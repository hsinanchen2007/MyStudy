回溯
```
class Solution {
public:
    ListNode* ret=nullptr;
    int count;
    ListNode* getKthFromEnd(ListNode* head, int k) {
      if(!head) return nullptr;
      else
      {
        getKthFromEnd(head->next,k);
        count++;
        if(k==count){
            ret=head;
        }
      }
     return ret;
    }
};
```

