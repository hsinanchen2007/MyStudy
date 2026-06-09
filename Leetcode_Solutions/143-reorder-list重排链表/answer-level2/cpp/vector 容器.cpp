```
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> s;
        ListNode* p = head;
        while(p) {
            s.push_back(p);
            p = p->next;
        }
        if(s.size() <= 2) {
            return;
        }

        p = head;
        int size = s.size();
        for(int i = 0; i < size / 2; i++) {
            ListNode* next = p->next;
            p->next = s.back();
            s.pop_back();
            p->next->next = next;
            p = next;
        }
        p->next = NULL;
        return;
    }
};

```
