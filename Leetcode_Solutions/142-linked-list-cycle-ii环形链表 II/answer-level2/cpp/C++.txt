```
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> myset;
        while(head!=nullptr)
        {
            if(myset.count(head)>0)
                return head;
            else
                myset.insert(head);
            head=head->next;
        }
        return nullptr;
    }
};

```