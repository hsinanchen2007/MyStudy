```
class Solution {
public:
    bool hasCycle(ListNode *head) {
       if(!head)
            return false;
        unordered_set<ListNode*> set;
        while(head!=NULL){
            if(set.count(head)==0){
                    set.insert(head);
                    head=head->next;
                }
            else
                return true;
        } 
         return false;
    }
};
```