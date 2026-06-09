```
class Solution {
public:
    typedef pair<int, ListNode*> PIL;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        auto dummy = new ListNode(-1), p = dummy;
        priority_queue<PIL, vector<PIL>, greater<PIL>> heap;
        for(int i = 0; i < lists.size(); i ++) {
            auto l = lists[i];
            if(l)  heap.push({l->val, l});
        }

        while(!heap.empty()) {
            auto item = heap.top();
            heap.pop();
            p->next = item.second;
            p = p->next;
            if(item.second->next) heap.push({item.second->next->val, item.second->next});
        }
        return dummy->next;
    }
};
```
